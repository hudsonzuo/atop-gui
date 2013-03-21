#include <QApplication>
#include "../curveanalyzer.h"
#include "mainwindow.h"

int main(int argc, char *argv[])
{
	QApplication app(argc, argv);

	MainWindow w;

	QMap<QString, int> data;
	data["Chromium"] = 4;
	data["Firefox"] = 6;
	
	CurveAnalyzer *ca = new CurveAnalyzer();
	ca->updateData(data);
		
	w.addPage(ca, "CurveAnalyzer");
	w.resize(800, 600);
	w.show();

	return app.exec();
}

















