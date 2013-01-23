#include <QApplication>
#include "../curveanalyzer.h"
#include "mainwindow.h"

int main(int argc, char *argv[])
{
	QApplication app(argc, argv);

	MainWindow w;

	CurveAnalyzer *ca = new CurveAnalyzer();
	w.addPage(ca, "CurveAnalyzer");
	
	w.show();

	return app.exec();
}

















