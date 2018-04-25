#pragma once
#include <qstring.h>
#include <qspinbox.h>


class UserSpinBox:public QDoubleSpinBox
{
	Q_OBJECT
public:
	UserSpinBox() {};
	~UserSpinBox() {};

public slots:
void setStepFromComboBox(QString str)
{
	setSingleStep(str.toDouble());
}

private:

};



