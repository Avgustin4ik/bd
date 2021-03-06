#pragma once
#include "Vertex2D.h"
using namespace std;
template <typename T>
class Circle
{
public:
	Circle();
	Circle(const T _radius, const Vertex2D<T> _c);
	Circle(const Vertex2D<T> _c);
	~Circle();

	T radius;
	Vertex2D<T> centr;
	QVector<double> getXarray();
	QVector<double> getYarray();

	//virtual ObjectType getObjectType() final;
private:
	vector<Vertex2D<T>> points;
};
template <typename T>
Circle<T>::Circle()
	: radius(1.0), centr(0.0, 0.0)
{

}
template <typename T>
Circle<T>::Circle(const T _radius, const Vertex2D<T> _c)
	: radius(_radius), centr(_c)
{
}
template<typename T>
inline Circle<T>::Circle(const Vertex2D<T> _c)
	: radius(0.05), centr(_c)
{

}
template <typename T>
Circle<T>::~Circle()
{
}
template <typename T>
QVector<double> Circle<T>::getXarray()
{
	QVector<double> res;
	res.reserve(100);
	for (T a = 0; a <= 2 * PI; a += (PI / 100))
		res.push_back(radius * cos(a) + centr.x);
	return res;
}
template <typename T>
QVector<double> Circle<T>::getYarray()
{
	QVector<double> res;
	res.reserve(100);
	for (T a = 0; a <= 2 * PI; a += (PI / 100))
		res.push_back(radius * sin(a) + centr.y);
	return res;
}

