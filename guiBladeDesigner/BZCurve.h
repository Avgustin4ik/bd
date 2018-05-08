#pragma once
#include "BezierCurve.h"
#include "qcustomplot.h"

template<typename T>
class BZCurve:public BezierCurve<T>
{
public:
	QCPCurve *curve;
	QCPCurve *parametrs_line;
	BZCurve(QCPCurve *_curve, QCPCurve *_parametric_line);
	~BZCurve();
	void recompute();

private:
	double splittingStep;
	QVector<double> getPX();
	QVector<double> getPY();
	QVector<double> getBX();
	QVector<double> getBY();

};

template<typename T>
inline BZCurve<T>::BZCurve(QCPCurve *_curve, QCPCurve *_parametric_line):BezierCurve<T>()/*,curve(_curve), parametrs_line(_parametric_line)*/
{
	curve = _curve;
	parametrs_line = _parametric_line;
	recompute();
}

template<typename T>
inline BZCurve<T>::~BZCurve()
{
}

template<typename T>
inline void BZCurve<T>::recompute()
{
	curve->setData(getBX(), getBY());
	parametrs_line->setData(getPX(), getPY());
}
template<typename T>
inline QVector<double> BZCurve<T>::getPX()
{
	QVector<double> result;
	for (auto &i:this->PPoints) result.push_back(i.x);
	return result;
}
template<typename T>
inline QVector<double> BZCurve<T>::getPY()
{
	QVector<double> result;
	for (auto &i : this->PPoints) result.push_back(i.y);
	return result;
}
template<typename T>
inline QVector<double> BZCurve<T>::getBX()
{
	QVector<double> result;
	for (double t = 0.0; t <= 1.0; t = t + (1.0 / splittingStep)) result.push_back(this->getPoint(t).x);
	return result;
}
template<typename T>
inline QVector<double> BZCurve<T>::getBY()
{
	QVector<double> result;
	for (double t = 0.0; t <= 1.0; t = t + 1.0 / splittingStep) result.push_back(this->getPoint(t).y);
	return result;
}

