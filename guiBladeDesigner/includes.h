#pragma once
#include <qcustomplot.h>
//#include "cppoptlib\meta.h"
//#include "cppoptlib\problem.h"
//#include "cppoptlib\solver\bfgssolver.h"
#include <BezierCurve.h>
#include <Objective_function.h>
#include <Condition.h> 
#include <Circle.h>
#include <Flags.h>
#include "SidesFunction.h"

template <typename T>
vector<Vertex2D<T>> getEdgePoints(const bool &isLeadingEdge, BezierCurve<T> &curve, const T &omega, const T &radius)
{
	if (omega > 180 || omega < 0) throw(exception());
	Vector2D<T> tangent;
	Vertex2D<T> P;
	vector<Vertex2D<T>> points;
	points.reserve(2);
	float64 _omega(omega);
	if (!isLeadingEdge) _omega *= -1;
	float64 angle = PI / 2 - RAD(_omega / 2);
	if (isLeadingEdge) {
		P = curve.PPoints[0];
		tangent = curve.dt(0);
	}
	else {
		P = curve.PPoints[curve.PPoints.size() - 1];
		tangent = curve.dt(1);
	}
	float64 phi = PI - angle;
	Vector2D<T> direct1 = tangent + phi;
	Vector2D<T> direct2 = tangent - phi;
	points.emplace_back(P + direct1 * radius);
	points.emplace_back(P + direct2 * radius);
	return points;
}
