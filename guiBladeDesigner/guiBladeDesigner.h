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
private:
	Ui::guiBladeDesignerClass ui;
	QPen ppPen;
	QPen bzPen;
	Vertex2D<float32> &xMax = Vertex2D<float32>();
	float32 &m_xMax = xMax.x;
	float32 &m_yMax = xMax.y;
	BezierCurve<float32> &camberCurve = BezierCurve<float32>();
	BezierCurve<float32> &lineCurve = BezierCurve<float32>(vector < Vertex2D<float32>>({Vertex2D<float32>(0,0), Vertex2D<float32>(1,0)}));
	CamberLineFunction<float32> *fCmaber;
	double m_alpha1;
	double m_alpha2;
	QVector<double> getPX(BezierCurve<float32> &curve);
	QVector<double> getPY(BezierCurve<float32> &curve);
	QVector<double> getBX(BezierCurve<float32> &curve);
	QVector<double> getBY(BezierCurve<float32> &curve);

};
