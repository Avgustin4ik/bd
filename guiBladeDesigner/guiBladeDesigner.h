#pragma once
#include <QtWidgets/QMainWindow>
#include "ui_guiBladeDesigner.h"
#include <qdebug.h>
#include <includes.h>


class guiBladeDesigner : public QMainWindow
{
	Q_OBJECT
public:
	guiBladeDesigner(QWidget *parent = Q_NULLPTR);

private slots:
	void plotCurve(BezierCurve<float32> &curve);
	void plotPoint(const Vertex2D<float32> &ptr);
	void plotCurvature(BezierCurve<float32> &curve);
	void updateCamberline();
	void camberButtonClicked();
	void read_xMax();
	void read_camberAngles();
	void read_edge();
private:
	Ui::guiBladeDesignerClass ui;
	QPen ppPen;
	QPen bzPen;
	QPen &assistPen = QPen(Qt::darkGreen, 2, Qt::DashLine);
	//temporaly geometry objects
	BezierCurve<float32> &temp_camber1 = BezierCurve<float32>();//need new class
	BezierCurve<float32> &temp_camber2 = BezierCurve<float32>();//need new class

	Vertex2D<float32> &xMax = Vertex2D<float32>();
	float32 &m_xMax = xMax.x;
	float32 &m_yMax = xMax.y;
	BezierCurve<float32> &camberCurve = BezierCurve<float32>();
	BezierCurve<float32> &lineCurve = BezierCurve<float32>(vector < Vertex2D<float32>>({Vertex2D<float32>(0,0), Vertex2D<float32>(1,0)}));
	CamberLineFunction<float32> *fCmaber;
	float32 m_alpha1;
	float32 m_alpha2;
	Circle<float32> &inletEdge = Circle<float32>(Vertex2D<float32>(0,0));
	Circle<float32> &outletEdge = Circle<float32>(Vertex2D<float32>(1,0));
	QCPItemEllipse *qcp_inletEdge;
	QCPItemEllipse *qcp_outletEdge;
	float32 &inlet_radius = inletEdge.radius;
	float32 inlet_omega;
	float32 &outlet_radius = outletEdge.radius;
	float32 outlet_omega;
	QVector<double> getPX(BezierCurve<float32> &curve);
	QVector<double> getPY(BezierCurve<float32> &curve);
	QVector<double> getBX(BezierCurve<float32> &curve);
	QVector<double> getBY(BezierCurve<float32> &curve);

};
