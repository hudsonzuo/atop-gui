#include <QApplication>
#include "../curveanalyzer.h"
#include "mainwindow.h"

int main(int argc, char *argv[])
{
	QApplication app(argc, argv);

	MainWindow w;

	CurveAnalyzer *ca = new CurveAnalyzer();
	ca->updateData(QByteArray("{\"Chromium\": 4, \"firefox\": 6}"));
		
	w.addPage(ca, "CurveAnalyzer");
	w.show();

	return app.exec();
}

















