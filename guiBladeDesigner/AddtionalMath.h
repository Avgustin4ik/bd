#pragma once
#include <Setups.h>


template<typename F, typename T>
class derivarive
{
public:
	derivarive(F& f, const T& h) :f(f), h(h) {}
	T operator () (std::vector<T>& var_arr, size_t i)
	{

		vector<T> delta_plus(var_arr);
		vector<T> delta_minus(var_arr);
		delta_plus[i] = delta_plus[i] + h;
		delta_minus[i] = delta_minus[i] - h;
		return (f(delta_plus) - f(delta_minus)) / (2 * h);
	}
	const T operator () (const std::vector<T> &var_arr, size_t i) const
	{
		vector<T> delta_plus(var_arr);
		vector<T> delta_minus(var_arr);
		delta_plus[i] = delta_plus[i] + h;
		delta_minus[i] = delta_minus[i] - h;
		return (f(delta_plus) - f(delta_minus)) / (2 * h);
	}

	Matrix<T> operator ()(const std::vector<T>& var)
	{
		size_t size = var.size();
		Matrix<T> result(size, 1);
		for (size_t i = 0; i < size; i++)
		{
			vector<T> delta_plus(var);
			vector<T> delta_minus(var);
			delta_plus[i] = delta_plus[i] + h;
			delta_minus[i] = delta_minus[i] - h;
			T a = (f(delta_plus) - f(delta_minus)) / (2 * h);
			result(i, 0) = EQUAL(a, 0.0);
		}
		return result;
	}

private:
	F & f;
	T h;
};

template <typename F, typename T>
void method_bisection(F& f, std::vector<T> &variables, const T left_border, const T right_border)
{
	using d_f = derivarive<F, T>;
	T h = 0.001;
	d_f df(f, h);
	T& x = variables[0];
	T a = left_border;
	T b = right_border;
	x = (a + b) / 2;
	vector<float32> new_variables;
	new_variables.push_back(x);
	T& xn = new_variables[0];
	auto dfx = df(new_variables, 0);
	if (dfx < 0)
	{
		a = xn;
	}
	else
	{
		b = xn;
	}
	xn = (a + b) / 2;
	auto fx = f(variables);
	auto fxn = f(new_variables);
	while (fabsf(f(new_variables) - f(variables)) > (1e-4))
	{
		x = xn;
		dfx = df(new_variables, 0);
		if (dfx < 0)
		{
			a = xn;
		}
		else
		{
			b = xn;
		}
		xn = (a + b) / 2;
	}
	x = xn;
}
