#pragma once
#include <QtWidgets/QMainWindow>
#include "ui_guiBladeDesigner.h"
#include <qdebug.h>
#include <includes.h>
#include <QtGui>
#include <QtCore>
#include <UserSpinBox.h>
#include <CamberCircle.h>
#include <BZCurve.h>

class guiBladeDesigner : public QMainWindow
{
	Q_OBJECT
public:
	guiBladeDesigner(QWidget *parent = Q_NULLPTR);

	
private slots:
//POEHALI
	void plotCurve(BezierCurve<float32> &curve);
	void plotPoint(const Vertex2D<float32> &ptr);
	void plotCurvature();
	void plot(BoundaryConditions<float32> &conditions);
	void plot(vector<FishBone<float32>> &fb);
	void plotTangents();
	//void plot(QCPCurve *curve);
	void updateCamberline();
	void camberButtonClicked();
	void suctionSideButtonClicked();
	void read_xMax();
	void read_camberAngles();
	void read_edge();
	void read_maxCircle();
	void read_bendCircle();
	void readAll();
	void updateQCPCircle(QCPItemEllipse *qcp, const Circle<float32> &c);
	void updateQCPCircle(QCPItemEllipse *qcp, const Vertex2D<float32> &c, const float32 &r);
	BoundaryConditions<float32> getBoundaryConditions(const bool isForSuctionSide);
	void readFile();
	void saveFile();
	void export2AutoCad();
	void readingProtocol(QStringList &str);
	//void savingProtocol();

public:
	template<typename T>
	void minimization(SidesFunction<T> &f, VectorXd &xd);
private:
	//poiters magic
	QList<QPointer<UserSpinBox>> listSpinBoxes();
	QList<QPointer<QComboBox>> listComboBoxes();
	void tableConfig(QTableWidget *table , QList<QPointer<UserSpinBox>> listSP, QList<QPointer<QComboBox>> listCB);

	
private:
	QList <QPointer<QComboBox>> listCMB;
	QList<QPointer<UserSpinBox>> listUSBox;
	Ui::guiBladeDesignerClass ui;
	QPen ppPen;
	QPen bzPen;
	QPen &assistPen = QPen(Qt::darkGreen, 2, Qt::DashLine);
	//temporaly geometry objects
	vector<Vertex2D<float32>> &inletEdgePoints = vector<Vertex2D<float32>>();
	vector<Vertex2D<float32>> &outletEdgePoints = vector<Vertex2D<float32>>();
	BoundaryConditions<float32> &suctionSideBC = BoundaryConditions<float32>();
	BoundaryConditions<float32> &pressureSideBC = BoundaryConditions<float32>();
	//ui ptr objects
	QTableWidget *tableParametrs;

	Vertex2D<float32> &xMax = Vertex2D<float32>();
	float32 &m_xMax = xMax.x;
	float32 &m_yMax = xMax.y;
	BezierCurve<float32> &camberCurve = BezierCurve<float32>();
	BezierCurve<float32> &lineCurve = BezierCurve<float32>(vector < Vertex2D<float32>>({Vertex2D<float32>(0,0), Vertex2D<float32>(1,0)}));
	BezierCurve<float32> &suctionSide = BezierCurve<float32>();
	BezierCurve<float32> &pressureSide = BezierCurve<float32>();
	
	float32 m_alpha1;
	float32 m_alpha2;
	Circle<float32> &inletEdge = Circle<float32>(Vertex2D<float32>(0,0));
	Circle<float32> &outletEdge = Circle<float32>(Vertex2D<float32>(1,0));
	Circle<float32> &maxCircle = Circle<float32>();
	Circle<float32> &bendCircle = Circle<float32>();
	//graphic items
	QCPItemEllipse *qcp_inletEdge;
	QCPItemEllipse *qcp_outletEdge;
	QCPItemEllipse *qcp_maxCircle;
	QCPItemEllipse *qcp_bendCircle;
	QCPCurve *camberPP;
	QCPCurve *camberBZ;
	QCPCurve *suctionPP;
	QCPCurve *suctionBZ;
	QCPCurve *pressurePP;
	QCPCurve *pressureBZ;
	QCPCurve *curvature_camber;
	QCPCurve *curvature_suction;
	QCPCurve *curvature_pressure;
	BZCurve<float32> *line_camber;
	BZCurve<float32> *line_suction;
	BZCurve<float32> *line_pressure;
	
	//blade parametrs
	float32 &inlet_radius = inletEdge.radius;
	float32 inlet_omega;
	float32 &outlet_radius = outletEdge.radius;
	float32 outlet_omega;
	float32 &m_rMax = maxCircle.radius;
	float32 &m_xrMax = maxCircle.centr.x;
	float32 &m_xBend = bendCircle.centr.x;
	float32 &m_rBend = bendCircle.radius;
	float32 m_alphaBend;
	BoundaryConditions<float32> conditions;
	QVector<double> getPX(BezierCurve<float32> &curve);
	QVector<double> getPY(BezierCurve<float32> &curve);
	QVector<double> getBX(BezierCurve<float32> &curve);
	QVector<double> getBY(BezierCurve<float32> &curve);
	Flags flags;
	
};


