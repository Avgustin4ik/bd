#include "guiBladeDesigner.h"

BezierCurve<float32> FishBone<float32>::skeleton;
guiBladeDesigner::guiBladeDesigner(QWidget *parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);
	ui.statusBar->showMessage("Poehali!");
	ui.globalPlot->xAxis->setRange(-0.25, 1.25);
	ui.globalPlot->yAxis->setRange(-0.5, 0.5);
	ui.additionalPlot->xAxis->setRange(0, 1);
	ui.globalPlot->setInteractions(QCP::iRangeDrag | QCP::iRangeZoom | QCP::iSelectPlottables);
	qcp_inletEdge = new QCPItemEllipse(ui.globalPlot);
	qcp_outletEdge = new QCPItemEllipse(ui.globalPlot);
	qcp_maxCircle = new QCPItemEllipse(ui.globalPlot);
	qcp_bendCircle = new QCPItemEllipse(ui.globalPlot);
	qcp_inletEdge->setPen(assistPen);
	qcp_outletEdge->setPen(assistPen);
	qcp_maxCircle->setPen(assistPen);
	qcp_bendCircle->setPen(assistPen);
	tableParametrs = ui.parametrsTable;
	listUSBox = listSpinBoxes();
	listCMB = listComboBoxes();
	tableConfig(tableParametrs, listUSBox, listCMB);
	//Variables initializion
	read_edge();
	qcp_inletEdge->bottomRight->setCoords(inlet_radius, -inlet_radius);
	qcp_inletEdge->topLeft->setCoords(-inlet_radius, inlet_radius);
	read_xMax();
	read_camberAngles();
	read_bendCircle();
	plotPoint(xMax);
	camberBZ = new QCPCurve(ui.globalPlot->xAxis, ui.globalPlot->yAxis);
	camberPP = new QCPCurve(ui.globalPlot->xAxis, ui.globalPlot->yAxis);
	camberPP->setScatterStyle(QCPScatterStyle(QCPScatterStyle::ssCircle, Qt::red, Qt::white, 12));
	suctionBZ = new QCPCurve(ui.globalPlot->xAxis, ui.globalPlot->yAxis);
	suctionPP = new QCPCurve(ui.globalPlot->xAxis, ui.globalPlot->yAxis);
	suctionPP->setScatterStyle(QCPScatterStyle(QCPScatterStyle::ssCircle, Qt::red, Qt::white, 12));
	pressureBZ = new QCPCurve(ui.globalPlot->xAxis, ui.globalPlot->yAxis);
	pressurePP = new QCPCurve(ui.globalPlot->xAxis, ui.globalPlot->yAxis);
	pressurePP->setScatterStyle(QCPScatterStyle(QCPScatterStyle::ssCircle, Qt::red, Qt::white, 12));
	
	curvature_camber = new QCPCurve(ui.additionalPlot->xAxis, ui.additionalPlot->yAxis);
	curvature_suction = new QCPCurve(ui.additionalPlot->xAxis, ui.additionalPlot->yAxis);
	curvature_pressure = new QCPCurve(ui.additionalPlot->xAxis, ui.additionalPlot->yAxis);
	curvature_camber->setPen(QPen(Qt::blue, 2, Qt::DashLine));
	curvature_suction->setPen(QPen(Qt::red, 4, Qt::SolidLine));
	curvature_pressure->setPen(QPen(Qt::green, 4, Qt::SolidLine));
	//Pen settings
	ppPen.setColor(Qt::red);	ppPen.setWidth(4);	ppPen.setStyle(Qt::DashLine);
	bzPen.setColor(Qt::blue);	bzPen.setWidth(4);	bzPen.setStyle(Qt::SolidLine);
	camberPP->setPen(ppPen);
	camberBZ->setPen(bzPen);
	suctionPP->setPen(ppPen);
	suctionBZ->setPen(bzPen);
	pressurePP->setPen(ppPen);
	pressureBZ->setPen(bzPen);
	QTextCodec *codec = QTextCodec::codecForName("UTF8");
	QTextCodec::setCodecForLocale(codec);
	//SIGNAL - SLOT connection
	connect(ui.actionRead, SIGNAL(triggered()), this, SLOT(readFile()));
	connect(ui.actionSave, SIGNAL(triggered()), this, SLOT(saveFile()));
	connect(ui.actionExport_to_AutoCad, SIGNAL(triggered()), this, SLOT(export2AutoCad()));
	//new slots
	for (int i = 0; i < listCMB.size(); i++)
	{
		connect(listUSBox[i], SIGNAL(valueChanged(double)), this, SLOT(readAll()));
		connect(listCMB[i], SIGNAL(currentIndexChanged(QString)), listUSBox[i], SLOT(setStepFromComboBox(QString)));
	}
	//Math setup
	connect(ui.computeCamberButton, SIGNAL(clicked()), this, SLOT(camberButtonClicked()));
	connect(ui.computeSuctionSideButton, SIGNAL(clicked()), this, SLOT(suctionSideButtonClicked()));
}


void guiBladeDesigner::plotCurve(BezierCurve<float32> &curve)
{
	QCPCurve &PP = QCPCurve(ui.globalPlot->xAxis, ui.globalPlot->yAxis);
	QCPCurve &BZ = QCPCurve(ui.globalPlot->xAxis, ui.globalPlot->yAxis);
	PP.addData(getPX(curve), getPY(curve));
	BZ.addData(getBX(curve), getBY(curve));
	PP.setScatterStyle(QCPScatterStyle(QCPScatterStyle::ssCircle, Qt::red, Qt::white, 12));
	PP.setPen(ppPen);
	BZ.setPen(bzPen);
	ui.globalPlot->replot();
}

void guiBladeDesigner::plotCurvature()
{
	
	QVector<double> x, yC, yS, yP;
	for (int i = 0; i<=100; i++)
	{
		double t = double(i) / 100.0;
		x << t;
		yC << camberCurve.curvature(t);
		yS << suctionSide.curvature(t);
		yP << pressureSide.curvature(t);
	}
	curvature_camber->setData(x, yC);
	curvature_suction->setData(x, yS);
	curvature_pressure->setData(x, yP);
	ui.additionalPlot->yAxis->rescale(true);
	ui.additionalPlot->replot();
}

void guiBladeDesigner::plot(BoundaryConditions<float32>& conditions)
{
	for (size_t i = 0; i < conditions.size(); i++)
	{
		int z = ui.globalPlot->graphCount();
		ui.globalPlot->addGraph();
		QVector<double> x, y;
		Vector2D<float32> &v(conditions(i).vector);
		x.push_back(conditions(i).point.x);
		x.push_back((conditions(i).point + v * 0.1).x);
		y.push_back(conditions(i).point.y);
		y.push_back((conditions(i).point + v * 0.1).y);
		ui.globalPlot->graph(z)->setData(x, y);
		ui.globalPlot->graph(z)->setPen(QPen(Qt::yellow, 2, Qt::DashLine));
		ui.globalPlot->replot();
	}
}

void guiBladeDesigner::plot(vector<FishBone<float32>>& fb)
{
	for (auto &i : fb)
	{
		int z = ui.globalPlot->graphCount();
		ui.globalPlot->addGraph();
		ui.globalPlot->graph(z)->addData(i.getPointOnSkeleton().x, i.getPointOnSkeleton().y);
		ui.globalPlot->graph(z)->addData(i.getPoint().x, i.getPoint().y);
		ui.globalPlot->replot();
	}
}

void guiBladeDesigner::plotTangents()
{
	vector<Vector2D<float32>> tangents;
	vector<Vertex2D<float32>> points;
	vector<float32> t;
	t.reserve(2);
	t.emplace_back(suctionSide.find_nearest(suctionSideBC(1).point));
	t.emplace_back(suctionSide.find_nearest(suctionSideBC(2).point));
	points.reserve(2);
	points.emplace_back(suctionSide.getPoint(t[0]));
	points.emplace_back(suctionSide.getPoint(t[1]));
	tangents.reserve(2);
	tangents.emplace_back(suctionSide.dt(t[0]));
	tangents.emplace_back(suctionSide.dt(t[1]));
	int z = ui.globalPlot->graphCount();
	ui.globalPlot->addGraph();
	ui.globalPlot->addGraph();
	QVector<double> X, Y;
	X.push_back(points[0].x);
	X.push_back((points[0] + tangents[0] * 0.1).x);
	Y.push_back(points[0].y);
	Y.push_back((points[0] + tangents[0] * 0.1).y);
	ui.globalPlot->graph(z)->setData(X, Y);
	X.clear(); Y.clear();
	X.push_back(points[1].x);
	X.push_back((points[1] + tangents[1] * 0.1).x);
	Y.push_back(points[1].y);
	Y.push_back((points[1] + tangents[1] * 0.1).y);
	ui.globalPlot->graph(z + 1)->setData(X, Y);
	ui.globalPlot->graph(z)->setPen(QPen(Qt::red, 2, Qt::DashLine));
	ui.globalPlot->graph(z + 1)->setPen(QPen(Qt::red, 2, Qt::DashLine));
	ui.globalPlot->replot();
}


void guiBladeDesigner::updateCamberline()
{
	read_xMax();
	read_camberAngles();
	if (camberBZ->dataCount() == 0)
	{
		camberBZ->addData(getBX(camberCurve), getBY(camberCurve));
		camberPP->addData(getPX(camberCurve), getPY(camberCurve));
	}
	else
	{
		camberBZ->setData(getBX(camberCurve), getBY(camberCurve));
		camberPP->setData(getPX(camberCurve), getPY(camberCurve));
	}
	ui.globalPlot->replot();
	plotPoint(xMax);
}

void guiBladeDesigner::camberButtonClicked()
{
	ui.globalPlot->clearGraphs();
	using namespace cppoptlib;
	CamberLineFunction<float32> fCamber(camberCurve, lineCurve, xMax);
	BfgsSolver<CamberLineFunction<float32>> solver;
	VectorXd x(2); x << 0.3, 0.3;
	while (fCamber.value(x) > 1e-3)
	{
		solver.minimize(fCamber, x);
		vector<float32> vx;
		for (size_t i = 0; i < x.size(); i++)	vx.emplace_back(x[i]);
		fCamber.recompute(vx);
		if (fCamber.value(x) > 1e-3)
		{
			fCamber.add_PPoint(x);
		}
		else break;
		if (camberCurve.m > 10) break;
	}
	vector<float32> vx;
	for (size_t i = 0; i < x.size(); i++)	vx.emplace_back(x[i]);
	fCamber.recompute(vx);
	if (camberBZ->dataCount() == 0)
	{
		camberBZ->addData(getBX(camberCurve), getBY(camberCurve));
		camberPP->addData(getPX(camberCurve), getPY(camberCurve));
	}
	else
	{
		camberBZ->setData(getBX(camberCurve), getBY(camberCurve));
		camberPP->setData(getPX(camberCurve), getPY(camberCurve));
	}
	ui.globalPlot->replot();
	plotCurvature();
	flags.isCLineCompute = true;
	readAll();
	ui.statusBar->showMessage("Camber Line is compute!	f(x)=" + QString::number(fCamber.value(x)),5000);
	suctionSideBC = getBoundaryConditions(true);
	pressureSideBC = getBoundaryConditions(false);
	for (size_t i = 0; i < suctionSideBC.size(); i++)	plotPoint(suctionSideBC.data[i].point);
	for (size_t i = 0; i < pressureSideBC.size(); i++)	plotPoint(pressureSideBC.data[i].point);
	
	//suciton side math
	vector<float32> tVec, gammaVec;
	tVec.reserve(camberCurve.PPoints.size() - 2);
	gammaVec.reserve(camberCurve.PPoints.size() - 2);
	for (size_t i = 2; i < camberCurve.PPoints.size() - 2; i++)
	{
		tVec.emplace_back(camberCurve.find_nearest(camberCurve.PPoints[i]));
		gammaVec.emplace_back(0.3);
	}
	ui.computeSuctionSideButton->setEnabled(true);
	float32 angle1 = m_alpha1 + float(inlet_omega / float(2.0));
	float32 angle2 = m_alpha2 + outlet_omega / 2.0;
	suctionSide = camberCurve.shift_curve(true, inletEdgePoints[0], outletEdgePoints[0], tVec, gammaVec, angle1, angle2, 0.2, 0.2);
	if (suctionBZ->dataCount() != 0)
	{
		suctionBZ->setData(getBX(suctionSide), getBY(suctionSide));
		suctionPP->setData(getPX(suctionSide), getPY(suctionSide));
	}
	else
	{
		suctionBZ->addData(getBX(suctionSide), getBY(suctionSide));
		suctionPP->addData(getPX(suctionSide), getPY(suctionSide));
	}
	plot(suctionSideBC);
	plot(pressureSideBC);
	//plotCurve(suctionSide);
	tVec.clear();
	gammaVec.clear();
	tVec.reserve(camberCurve.PPoints.size() - 2);
	gammaVec.reserve(camberCurve.PPoints.size() - 2);
	for (size_t i = 2; i < camberCurve.PPoints.size() - 2; i++)
	{
		tVec.emplace_back(camberCurve.find_nearest(camberCurve.PPoints[i]));
		gammaVec.emplace_back(0.3);
	}
	angle1 = m_alpha1 - inlet_omega / 2.0;
	angle2 = m_alpha2 - outlet_omega / 2.0;
	pressureSide = camberCurve.shift_curve(false, inletEdgePoints[1], outletEdgePoints[1], tVec, gammaVec, angle1, angle2, 0.2, 0.1);
	if (pressureBZ->dataCount() != 0)
	{
		pressureBZ->setData(getBX(pressureSide), getBY(pressureSide));
		pressurePP->setData(getPX(pressureSide), getPY(pressureSide));
	}
	else
	{
		pressureBZ->addData(getBX(pressureSide), getBY(pressureSide));
		pressurePP->addData(getPX(pressureSide), getPY(pressureSide));
	}
	ui.globalPlot->replot();
}

template<typename T>
void guiBladeDesigner::minimization(SidesFunction<T>& f, VectorXd & xd)
{
	BfgsSolver<SidesFunction<T>> solver;
	T deps = 1e-2;
	T m_max = 12;
	while (f.value(xd) > deps)
	{	
		solver.minimize(f, xd);
		vector<T> xv(xd.size(), -100);
		for (int i = 0; i < xv.size(); i++) xv[i] = xd[i];
		f.setVariables(xv);
		/*
		**Добавил условие удаленности для двух первых и последних точек
		*/
		//vector<Vertex2D<T>> &pp = f.getCurve().PPoints;
		//vector<FishBone<T>> fbones = f.getFishBones();
		//bool isFBlower = false;
		//BezierCurve<T> &curve = f.getCurve();
		//for (size_t i = 1; i < fbones.size(); i++)
		//{
		//	Vertex2D<T> first = curve.PPoints[i];
		//	Vertex2D<T> second = curve.getPoint(curve.find_nearest(curve.PPoints[i]));
		//	if (f.isSuctionSide)
		//	{
		//		if (first.y - second.y <= 0.0)
		//			//if (fbones.at(i).getPoint().y <= f.getCurve().getPoint(f.getCurve().find_nearest(f.getCurve().PPoints[i])).y)
		//		{
		//			isFBlower = true;
		//			f.increaseCurve(xv);
		//			xd.resize(xv.size());
		//			for (int i = 0; i < xv.size(); i++) xd[i] = xv[i];
		//		}
		//	}
		//}
		if (f.getCurve().m > m_max) break;
		else if (f.value(xd)>deps)
		{
			f.setVariables(xv);
			f.increaseCurve(xv);
			xd.resize(xv.size());
			for (int i = 0; i < xv.size(); i++) xd[i] = xv[i];
		}
	}
}
void guiBladeDesigner::suctionSideButtonClicked()
{
	int startTime = clock();
	FishBone<float32>::skeleton = camberCurve;
	SidesFunction<float32> f(suctionSide, suctionSideBC, true, inlet_radius, outlet_radius);
	f.isSuctionSide = true;
	BfgsSolver<SidesFunction<float32>> solver;
	int size = suctionSide.PPoints.size() - 2;
	VectorXd x(size);
	for (size_t i = 0; i < size; i++) x[i] = 0.2;
	SidesFunction<float32> fps(pressureSide, pressureSideBC, false, inlet_radius, outlet_radius);
	fps.isSuctionSide = false;
	size = pressureSide.PPoints.size() - 2;
	VectorXd xp(size);
	for (size_t i = 0; i < size; i++) xp[i] = 0.2;
	std::thread one([this, &f, &x]() {minimization<float32>(f, x); });
	minimization<float32>(fps, xp);
	one.join();
	pressureBZ->setData(getBX(pressureSide), getBY(pressureSide));
	pressurePP->setData(getPX(pressureSide), getPY(pressureSide));
	suctionBZ->setData(getBX(suctionSide), getBY(suctionSide));
	suctionPP->setData(getPX(suctionSide), getPY(suctionSide));
	ui.globalPlot->replot();
	plotCurvature();
	int endTime = clock();
	ui.statusBar->showMessage("Time for minimization" + QString::number(endTime - startTime), 5000);
	flags.isWallsCompute = true;
}

void guiBladeDesigner::read_xMax()
{
	xMax.x = listUSBox[0]->value();
	xMax.y = listUSBox[1]->value();
	//plotPoint(xMax);
}

void guiBladeDesigner::read_camberAngles()
{
	m_alpha1 = listUSBox[2]->value();
	m_alpha2 = listUSBox[3]->value();
	using PP = vector<Vertex2D<float32>>;
	using P = Vertex2D<float32>;
	if (flags.isCLineCompute == true)
	{

	}
	else
	{
		camberCurve.setPPoints(PP(
			{ P(0.0,0.0),
			P(0.4 * cos(m_alpha1 * PI / 180.0), 0.4 *sin(m_alpha1 * PI / 180.0)),
			P(1 - 0.4 *cos(m_alpha2 * PI / 180.0), 0.4 *sin(m_alpha2 * PI / 180.0)),
			P(1.0, 0.0) }));
	}
	ui.globalPlot->replot();
}

void guiBladeDesigner::read_edge()
{

	inlet_radius = listUSBox[4]->value();
	outlet_radius = listUSBox[5]->value();
	inlet_omega = listUSBox[6]->value();
	outlet_omega = listUSBox[7]->value();
	updateQCPCircle(qcp_inletEdge, inletEdge);
	updateQCPCircle(qcp_outletEdge, outletEdge);
	ui.globalPlot->replot();
	if (flags.isCLineCompute)
	{
		inletEdgePoints = getEdgePoints(true, camberCurve, inlet_omega, inlet_radius);
		outletEdgePoints = getEdgePoints(false, camberCurve, outlet_omega , outlet_radius);
		for (auto &i : inletEdgePoints)	plotPoint(i);
		for (auto &i : outletEdgePoints) plotPoint(i);
	}
}

void guiBladeDesigner::read_maxCircle()
{
	m_rMax = listUSBox[8]->value();
	m_xrMax = listUSBox[9]->value();
	maxCircle.centr = camberCurve.getPointFromX(m_xrMax);
	updateQCPCircle(qcp_maxCircle, maxCircle);
	m_alphaBend = listUSBox[12]->value();
	ui.globalPlot->replot();
}

void guiBladeDesigner::read_bendCircle()
{
	m_rBend = listUSBox[10]->value();
	m_xBend = listUSBox[11]->value();
	bendCircle.centr = camberCurve.getPointFromX(m_xBend);
	updateQCPCircle(qcp_bendCircle, bendCircle);
	ui.globalPlot->replot();
}

void guiBladeDesigner::readAll()
{
	read_xMax();
	read_camberAngles();
	updateCamberline();
	read_edge();
	read_maxCircle();
	read_bendCircle();
}

void guiBladeDesigner::updateQCPCircle(QCPItemEllipse * qcp, const Circle<float32>& c)
{
	float32 x, y, r;
	x = c.centr.x;
	y = c.centr.y;
	r = c.radius;
	qcp->topLeft->setCoords(x - r, y + r);
	qcp->bottomRight->setCoords(x + r, y - r);
}

void guiBladeDesigner::updateQCPCircle(QCPItemEllipse * qcp, const Vertex2D<float32> & c, const float32 & r)
{
	qcp->topLeft->setCoords(c.x - r, c.y + r);
	qcp->topLeft->setCoords(c.x + r, c.y - r);
}

BoundaryConditions<float32> guiBladeDesigner::getBoundaryConditions(const bool isForSuctionSide)
{
	BoundaryConditions<float32> res;
	VertexCondition<float32> sc;
	int i = 0, k = 1;
	if (isForSuctionSide != true) { i = 1; k = -1; }
	//get inletEdge condition
	sc.point = inletEdgePoints[i];
	sc.vector = Vector2D<float32>(m_alpha1 + k * inlet_omega/2.0);
	res.addCondition(sc);
	//get maxCircle condition
	float32 t = camberCurve.find_nearest(maxCircle.centr);
	Vector2D<float32> vc;
	vc.normal2vector(camberCurve.dt(t), isForSuctionSide);
	sc.point = maxCircle.centr + vc * maxCircle.radius;
	sc.vector = Vector2D<float32>().normal2vector(vc, isForSuctionSide);
	res.addCondition(sc);
	//get bendCircle condition
	t = camberCurve.find_nearest(bendCircle.centr);
	vc = camberCurve.dt(t);
	float32 angle = DEG(acosf(vc*Vector2D<float32>(1, 0)));
	if (angle > 90)	angle = angle - 180;
	float32 bend_angle = 90;
	if (isForSuctionSide) 
		bend_angle = 90 - m_alphaBend / 2.0 - angle;
	else bend_angle = 0 - (90 - m_alphaBend / 2.0 + angle);
	Vector2D<float32> bv(bend_angle);
	sc.point = bendCircle.centr + bv * bendCircle.radius;
	sc.vector = Vector2D<float32>().normal2vector(bv, isForSuctionSide);
	res.addCondition(sc);
	//get outletEdge condition
	sc.point = outletEdgePoints[i];
	float32 angleOutletV;
	if (isForSuctionSide)	angleOutletV = PI - m_alpha2 - outlet_omega / 2.0;
	else angleOutletV =  - m_alpha2 + outlet_omega / 2.0;
	sc.vector = Vector2D<float32>(angleOutletV);
	res.addCondition(sc);
	return res;
}

void guiBladeDesigner::readFile()
{
	QString fileName = QFileDialog::getOpenFileName(this, "Open a file", "D://Work Roman/Qt Projects/projects/guiBladeDesigner/blades", "*.txt");
	QFile file(fileName);
	if (fileName.isEmpty())
	{
		return;
	}
	if (!file.open(QFile::ReadOnly | QFile::Text))
	{
		QMessageBox::warning(this, "Warning", "File not open! Default values has bean loaded");
		return;
	}
	QTextStream textStream(&file);
	QStringList parametrsTextList;
	while (!textStream.atEnd())	
		parametrsTextList.append(textStream.readLine());
	ui.statusBar->showMessage("Parametrs sucsessfully loaded", 3000);
	readingProtocol(parametrsTextList);
	parametrsTextList.clear();
	file.flush();
	file.close();
}

void guiBladeDesigner::saveFile()
{
	QString fileName = QFileDialog::getSaveFileName(this, "Open a file", "D://Work Roman/Qt Projects/projects/guiBladeDesigner/blades", "*.txt");
	QFile file(fileName);
	if (!file.open(QFile::WriteOnly | QFile::Text))
	{
		QMessageBox::warning(this, "Warning", "Could not open file for writing!");
		return;
	}
	QTextStream textStream(&file);
	QStringList parametrsTextList({
		QString::number(m_xMax) + QString("\n"),
		QString::number(m_yMax) + QString("\n"),
		QString::number(m_alpha1) + QString("\n"),
		QString::number(m_alpha2) + QString("\n"),
		QString::number(inlet_radius) + QString("\n"),
		QString::number(outlet_radius) + QString("\n"),
		QString::number(inlet_omega) + QString("\n"),
		QString::number(outlet_omega) + QString("\n"),
		QString::number(m_rMax) + QString("\n"),
		QString::number(m_xrMax) + QString("\n"),
		QString::number(m_rBend) + QString("\n"),
		QString::number(m_xBend) + QString("\n"),
		QString::number(m_alphaBend),
		});
	for (auto &i : parametrsTextList)
	{
		textStream << i;
	}
	file.flush();
	file.close();
}

void guiBladeDesigner::export2AutoCad()
{
	//prepearing
	double z(0.0);
	QVector<double> x(getBX(suctionSide)), y(getBY(suctionSide));
	QString endl("\n");

	QString fileName = QFileDialog::getSaveFileName(this, "Open a file", "D://Work Roman/Qt Projects/projects/guiBladeDesigner/blades", "*.txt");
	QFile file(fileName);
	if (!file.open(QFile::WriteOnly | QFile::Text))
	{
		QMessageBox::warning(this, "Warning", "Could not open file for writing!");
		return;
	}
	QTextStream textStream(&file);
	textStream.setCodec("UTF-8");
	
	//QStringList parametrsTextList;
	textStream << "_spline" + endl;
	//запись координат спинки
	for (size_t i = 0; i < x.size(); i++)
		textStream << QString::number(x[i]) + "," + QString::number(y[i]) + "," + QString::number(z) + endl;
	textStream << endl;
	Vertex2D<float32> s1(suctionSide.getPoint(0.0)), s2(suctionSide.getPoint(1.0)), p1(pressureSide.getPoint(0.0)), p2(pressureSide.getPoint(1.0));
	Vector2D<float32> vs1(suctionSide.dt(0.0)), vs2(suctionSide.dt(1.0)), vp1(pressureSide.dt(0.0)), vp2(pressureSide.dt(1.0));
	if (vs1.y > 0)	vs1.reverse();
	if (vs2.x < 0)	vs2.reverse();
	if (vp1.y > 0)	vp1.reverse();
	if (vp2.x < 0)	vp2.reverse();
	//Расчет и запись касательных в начальной и конечной точках SucitonSide
	Vertex2D<float32> p;
	p = s1 + vs1;
	textStream << QString::number(p.x) + "," + QString::number(p.y) + "," + QString::number(z) + endl;
	p = s2 + vs2;
	textStream << QString::number(p.x) + "," + QString::number(p.y) + "," + QString::number(z) + endl;
	textStream << endl;
	x.clear(); y.clear();
	x = getBX(pressureSide);
	y = getBY(pressureSide);
	for (size_t i = 0; i < x.size(); i++)
		textStream << QString::number(x[i]) + "," + QString::number(y[i]) + "," + QString::number(z) + endl;
	textStream << endl;
	//Расчет и запись касательных в начальной и конечной точках PressureSide
	p = p1 + vp1;
	textStream << QString::number(p.x) + "," + QString::number(p.y) + "," + QString::number(z) + endl;
	p = p2 + vp2;
	textStream << QString::number(p.x) + "," + QString::number(p.y) + "," + QString::number(z) + endl;
	//Входная кромка
	textStream << "_arc" + endl;
	textStream << QStringLiteral(u"Ц") + endl;
	textStream << QString::number(0.0) + "," + QString::number(0.0) + "," + QString::number(0.0) + endl;
	textStream << QString::number(s1.x) + "," + QString::number(s1.y) + endl;
	textStream << QString::number(p1.x) + "," + QString::number(p1.y) + endl;
	textStream << endl;
	//Выходная кромка
	textStream << "_arc" + endl;
	textStream << QStringLiteral(u"Ц") + endl;
	textStream << QString::number(1.0) + "," + QString::number(0.0) + "," + QString::number(0.0) + endl;
	textStream << QString::number(p2.x) + "," + QString::number(p2.y) + endl;
	textStream << QString::number(s2.x) + "," + QString::number(s2.y) + endl;

	file.flush();
	file.close();
}

void guiBladeDesigner::readingProtocol(QStringList & str)
{
	/*ui.xMaxEdit->setText(str[0]);
	ui.yMaxEdit->setText(str[1]);
	ui.alpha1Edit->setText(str[2]);
	ui.alpha2Edit->setText(str[3]);
	ui.inlet_radiusEdit->setText(str[4]);
	ui.outlet_radiusEdit->setText(str[5]);
	ui.inlet_omegaEdit->setText(str[6]);
	ui.outlet_omegaEdit->setText(str[7]);
	ui.rMaxEdit->setText(str[8]);
	ui.xRMaxEdit->setText(str[9]);
	ui.rBendEdit->setText(str[10]);
	ui.xBendEdit->setText(str[11]);
	ui.alphaBendEdit->setText(str[12]);*/
	for (int i = 0; i < str.size(); i++)
		listUSBox[i]->setValue(str[i].toDouble());
	readAll();
}


QList<QPointer<UserSpinBox>> guiBladeDesigner::listSpinBoxes()
{
	QList<QPointer<UserSpinBox>> list;
	for (int i = 0; i < tableParametrs->rowCount(); i++)
	{
		QPointer<UserSpinBox> sp = new UserSpinBox();
		sp->setParent(tableParametrs);
		sp->setSingleStep(0.01);
		sp->setDecimals(4);
		list.push_back(sp);
	}
	//задать границы в дальнейшем
	return list;
}

QList<QPointer<QComboBox>> guiBladeDesigner::listComboBoxes()
{
	QList<QPointer<QComboBox>> list;
	for (int i = 0; i < tableParametrs->rowCount(); i++)
	{
		QPointer<QComboBox> cb = new QComboBox(tableParametrs);
		QStringList temp({ "0.01","0.001","0.0001" });
		cb->insertItems(0, temp);
		list.push_back(cb);
	}
	//задать границы в дальнейшем
	return list;
}


void guiBladeDesigner::tableConfig(QTableWidget *table, QList<QPointer<UserSpinBox>> listSP, QList<QPointer<QComboBox>> listCB)
{
	
	for (int i = 0; i < table->rowCount(); i++)
	{
		table->setCellWidget(i, 0, listUSBox[i]);
		table->setCellWidget(i, 1, listCB[i]);
	}
}




void guiBladeDesigner::plotPoint(const Vertex2D<float32>& point)
{
	//ui.globalPlot->clearGraphs();
	//int i = ui.globalPlot->graphCount();
	//ui.globalPlot->addGraph();
	//QVector<double> x; x.push_back(point.x);
	//QVector<double> y; y.push_back(point.y);
	//ui.globalPlot->graph(i)->addData(x,y);
	//ui.globalPlot->graph(i)->setScatterStyle(QCPScatterStyle(QCPScatterStyle::ssDiamond, Qt::black, Qt::red, 15));
	//ui.globalPlot->replot();
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
	for (int i = 0; i <= 100; i = i + 1)
		x << curve.getPoint(double(i/100.0)).x;
	return x;
}

QVector<double> guiBladeDesigner::getBY(BezierCurve<float32>& curve)
{
	QVector<double> y;
	for (int i = 0; i <= 100; i = i + 1)
		y << curve.getPoint(double(i / 100.0)).y;
	return y;
}