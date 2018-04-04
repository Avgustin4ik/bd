#include "guiBladeDesigner.h"

guiBladeDesigner::guiBladeDesigner(QWidget *parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);
	ui.globalPlot->xAxis->setRange(-0.25, 1.25);
	ui.globalPlot->yAxis->setRange(-0.5, 0.5);
	ui.additionalPlot->xAxis->setRange(0, 1);
	ui.globalPlot->setInteractions(QCP::iRangeDrag | QCP::iRangeZoom | QCP::iSelectPlottables);
	qcp_inletEdge = new QCPItemEllipse(ui.globalPlot);
	qcp_outletEdge = new QCPItemEllipse(ui.globalPlot);
	qcp_inletEdge->setPen(assistPen);
	qcp_outletEdge->setPen(assistPen);

	read_edge();
	qcp_inletEdge->bottomRight->setCoords(inlet_radius, -inlet_radius);
	qcp_inletEdge->topLeft->setCoords(-inlet_radius, inlet_radius);
	//Variables initializion
	read_xMax();
	read_camberAngles();
	plotPoint(xMax);
	//Pen settings
	ppPen.setColor(Qt::red);	ppPen.setWidth(4);	ppPen.setStyle(Qt::DashLine);
	bzPen.setColor(Qt::blue);	bzPen.setWidth(4);	bzPen.setStyle(Qt::SolidLine);
	//SIGNAL - SLOT connection
	connect(ui.xMaxEdit, SIGNAL(editingFinished()), this, SLOT(updateCamberline()));
	connect(ui.yMaxEdit, SIGNAL(editingFinished()), this, SLOT(updateCamberline()));
	connect(ui.alpha1Edit, SIGNAL(editingFinished()), this, SLOT(updateCamberline()));
	connect(ui.alpha2Edit, SIGNAL(editingFinished()), this, SLOT(updateCamberline()));
	connect(ui.inlet_radiusEdit, SIGNAL(editingFinished()), this, SLOT(read_edge()));
	connect(ui.outlet_radiusEdit, SIGNAL(editingFinished()), this, SLOT(read_edge()));
	//Math setup
	using PP = vector<Vertex2D<float32>>;
	using P = Vertex2D<float32>;
	/*camberCurve.setPPoints(PP(
		{ P(0.0,0.0),
		P(0.5 * cos(60 * PI / 180.0), 0.5 *sin(60 * PI / 180.0)),
		P(1 - 0.5 *cos(21.5 * PI / 180.0), 0.5 *sin(21.5 * PI / 180.0)),
		P(1.0, 0.0) }));*/
	//read_xMax();
	connect(ui.computeCamberButton, SIGNAL(clicked()), this, SLOT(camberButtonClicked()));
}

void guiBladeDesigner::plotCurve(BezierCurve<float32> &curve)
{
	int i = ui.globalPlot->graphCount();
	ui.globalPlot->addGraph();
	ui.globalPlot->addGraph();
	auto graphPP = ui.globalPlot->graph(i);
	auto graphBZ = ui.globalPlot->graph(i+1);
	graphPP->setScatterStyle(QCPScatterStyle(QCPScatterStyle::ssCircle, Qt::red, Qt::white, 12));
	graphPP->setPen(ppPen);
	graphBZ->setPen(bzPen);
	graphPP->addData(getPX(curve), getPY(curve));
	graphBZ->addData(getBX(curve), getBY(curve));
	ui.globalPlot->replot();
}

void guiBladeDesigner::plotCurvature(BezierCurve<float32>& curve)
{
	int i = ui.additionalPlot->graphCount();
	QVector<double> x, y;
	for (double t = 0.0; t <= 1.0; t = t + 0.01)
	{
		x << t;
		y << curve.curvature(t);
	}
	ui.additionalPlot->addGraph();
	ui.additionalPlot->graph(i)->addData(x, y);
	ui.additionalPlot->yAxis->rescale(true);
	ui.additionalPlot->replot();
}



void guiBladeDesigner::updateCamberline()
{
	read_xMax();
	read_camberAngles();
	plotPoint(xMax);
	//m_alpha2 = ui.alpha2Edit->text().toDouble();
}

void guiBladeDesigner::camberButtonClicked()
{
	using namespace cppoptlib;
	CamberLineFunction<float32> fCamber(camberCurve, lineCurve, xMax);
	BfgsSolver<CamberLineFunction<float32>> solver;
	VectorXd x(2); x << 0.3, 0.3;
	VectorXd xInit(x);
	Criteria<double> stopCriteria;
	stopCriteria.iterations = 200;
	stopCriteria.xDelta = 1e-4;
	stopCriteria.fDelta = 1e-4;
	solver.setStopCriteria(stopCriteria);
	while (fCamber.value(x) > 1e-5)
	{
		solver.minimize(fCamber, x);
		vector<float32> vx;
		for (size_t i = 0; i < x.size(); i++)	vx.emplace_back(x[i]);
		fCamber.recompute(vx);
		if (fCamber.value(x) > 1e-3)
		{
			x = xInit;
			fCamber.add_PPoint(x);
			//vx.clear();
			//for (size_t i = 0; i < x.size(); i++)	vx.emplace_back(x[i]);
			//fCamber.recompute(vx);
			xInit = x;	
		}
		else break;
	}

	vector<float32> vx;
	for (size_t i = 0; i < x.size(); i++)	vx.emplace_back(x[i]);
	fCamber.recompute(vx);
	plotCurve(camberCurve);
	plotCurvature(camberCurve);
}

void guiBladeDesigner::read_xMax()
{
	xMax.x = ui.xMaxEdit->text().toFloat();
	xMax.y = ui.yMaxEdit->text().toFloat();
}

void guiBladeDesigner::read_camberAngles()
{
	m_alpha1 = ui.alpha1Edit->text().toFloat();
	m_alpha2 = ui.alpha2Edit->text().toFloat();
	using PP = vector<Vertex2D<float32>>;
	using P = Vertex2D<float32>;
	camberCurve.setPPoints(PP(
		{ P(0.0,0.0),
		P(0.5 * cos(m_alpha1 * PI / 180.0), 0.5 *sin(m_alpha1 * PI / 180.0)),
		P(1 - 0.5 *cos(m_alpha2 * PI / 180.0), 0.5 *sin(m_alpha2 * PI / 180.0)),
		P(1.0, 0.0) }));
}

void guiBladeDesigner::read_edge()
{
	inlet_radius = ui.inlet_radiusEdit->text().toFloat();
	inlet_omega = ui.inlet_omegaEdit->text().toFloat();
	outlet_radius = ui.outlet_radiusEdit->text().toFloat();
	outlet_omega = ui.outlet_omegaEdit->text().toFloat();
	qcp_inletEdge->topLeft->setCoords(-inlet_radius, inlet_radius);
	qcp_inletEdge->bottomRight->setCoords(inlet_radius, -inlet_radius);
	qcp_outletEdge->topLeft->setCoords(-outlet_radius + 1, outlet_radius);
	qcp_outletEdge->bottomRight->setCoords(outlet_radius + 1, -outlet_radius);
	ui.globalPlot->replot();
	//plot(inletEdge);
	//plot(outletEdge);

}

void guiBladeDesigner::plotPoint(const Vertex2D<float32>& point)
{
	ui.globalPlot->clearGraphs();
	int i = ui.globalPlot->graphCount();
	ui.globalPlot->addGraph();
	ui.globalPlot->graph(i)->addData(xMax.x,xMax.y);
	ui.globalPlot->graph(i)->setScatterStyle(QCPScatterStyle(QCPScatterStyle::ssDiamond, Qt::black, Qt::red, 15));
	ui.globalPlot->replot();
}


QVector<double> guiBladeDesigner::getPX(BezierCurve<float32>& curve)
{
	QVector<double> x;
	for (auto &i : curve.PPoints)	x << i.x;
	return x;
}

QVector<double> guiBladeDesigner::getPY(BezierCurve<float32>& curve)
{
	QVector<double> y;
	for (auto &i : curve.PPoints)	y << i.y;
	return y;
}

QVector<double> guiBladeDesigner::getBX(BezierCurve<float32>& curve)
{
	QVector<double> x;
	for (double t = 0.0; t <= 1.0; t = t + 0.01)
		x << curve.getPoint(t).x;
	return x;
}

QVector<double> guiBladeDesigner::getBY(BezierCurve<float32>& curve)
{
	QVector<double> y;
	for (double t = 0.0; t <= 1.0; t = t + 0.01)
		y << curve.getPoint(t).y;
	return y;
}

