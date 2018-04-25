//#pragma once
//#include "Vertex2D.h"
//#include "BezierCurve.h"
//#include <qcustomplot.h>
//#include "Ellipse.h"
//
//class CamberCircle : public QCPItemEllipse, public Ellipse
//{
//	Q_OBJECT
//public:
//	CamberCircle(QCustomPlot *parentPlot)
//		:Ellipse(), QCPItemEllipse(parentPlot)/*, camber()*/
//	{
//		recomputeRect();
//	};
//	~CamberCircle() {};
//	//������ �� ��������� �����
//	BezierCurve<float32> camber;
//	public slots:
//	//������������ ���������� ��� ��������� ������ �� X ����������
//	void recomputePosition(const double &p);
//	//������������ ���������� ��� ��������� ������ �� �����
//	void recomputePosition(const Vertex2D<double> &point);
//	//������������ ���������� ��� ��������� �������
//	void recomputeRadius(const double &r);
//	//������������ �� ���������� ����������, ��� ��������� ���� ������� ���� X ���������� ������
//	void recompute(const double &xCentr,const double &r);
//private:
//	void recomputeRect();
//};
//inline void CamberCircle::recomputePosition(const double &p)
//{
//	setCenter(camber.getPointFromX(p));
//	recomputeRect();
//}
//
//inline void CamberCircle::recomputePosition(const Vertex2D<double>& point)
//{
//	setCenter(point);
//	recomputeRect();
//}
//
//inline void CamberCircle::recomputeRadius(const double & r)
//{
//	setRadius(r);
//	recomputeRect();
//}
//
//inline void CamberCircle::recompute(const double &_xCenter,const double &_r)
//{
//	//Vertex2D<double> c = camber_ptr->getPointFromX(_xCenter);
//	Vertex2D<double> c = camber.getPointFromX(_xCenter);
//	double r = _r;
//	setCenter(c);
//	setRadius(r);
//	recomputeRect();
//}
//
//inline void CamberCircle::recomputeRect()
//{
//	topLeft->setCoords(getCenter().x - getRadius(), getCenter().y + getRadius());
//	bottomRight->setCoords(getCenter().x + getRadius(), getCenter().y - getRadius());
//}
