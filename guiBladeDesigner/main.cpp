#include "guiBladeDesigner.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	guiBladeDesigner w;
	w.show();
	return a.exec();
}
