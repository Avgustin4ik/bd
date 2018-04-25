#pragma once
#include <Setups.h>
using namespace std;
#define EQUAL(X,Y) ( ABS((X) - (Y)) <= 1e-6 ? (Y) : (X) )
#define ABS(X) ( (X) < 0 ? -(X) : (X) )

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
class second_derivative
{
public:
	second_derivative(F& f, const T& h) :h(h), fp(f, h), f(f) {}
	~second_derivative() {};
	T operator () (vector<T>& var_arr, size_t i, size_t di)
	{
		vector<T> delta_plus(var_arr);
		vector<T> delta_minus(var_arr);
		delta_plus[di] = delta_plus[di] + h;
		delta_minus[di] = delta_minus[di] - h;
		return (fp(delta_plus, i) - fp(delta_minus, i)) / (2 * h);
	}
	Matrix<T> operator ()(const vector<T>& var)
	{
		size_t size = var.size();
		Matrix<T> result(size, size);
		for (size_t j = 0; j < size; j++)
			for (size_t i = 0; i < size; i++)
			{
				size_t index = i * size + j;
				vector<T> delta_plus(var);
				vector<T> delta_minus(var);
				delta_plus[j] = delta_plus[j] + h;
				delta_minus[j] = delta_minus[j] - h;
				T a = (fp(delta_plus)(i, 0) - fp(delta_minus)(i, 0)) / (2 * h);
				result(i, j) = EQUAL(a, 0.0);
			}
		return result;
	}
private:
	T h;
	F& f;
	derivarive<F, T> fp;
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
	vector<T> new_variables;
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
