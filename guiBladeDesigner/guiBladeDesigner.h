#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_guiBladeDesigner.h"

class guiBladeDesigner : public QMainWindow
{
	Q_OBJECT

public:
	guiBladeDesigner(QWidget *parent = Q_NULLPTR);

private:
	Ui::guiBladeDesignerClass ui;
};
