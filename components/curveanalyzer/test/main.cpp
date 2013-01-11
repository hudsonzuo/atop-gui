#include <QApplication>
#include "../curveanalyzer.h"

int main(int argc, char *argv[])
{
	QApplication app(argc, argv);

	CurveAnalyzer w;
	w.show();

	return app.exec();
}
