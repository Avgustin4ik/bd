#pragma once
#include "Vertex2D.h"
class Ellipse
{
public:
	Ellipse():center(Vertex2D<double>(0,0)), radius(1.0) {};
	~Ellipse() {};
	void setRadius(const double &r) { radius = r; };
	void setCenter(const Vertex2D<double> &c) { center = c; };
	double getRadius() { return radius; };
	Vertex2D<double> getCenter() { return center; };

private:
	Vertex2D<double> center;
	double radius;
};