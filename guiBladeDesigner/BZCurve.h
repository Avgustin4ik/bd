#pragma once
#include "BezierCurve.h"
#include "qcustomplot.h"

template<typename T>
class BZCurve:public BezierCurve<T>
{
public:

private:
	double splittingStep;
	
};
