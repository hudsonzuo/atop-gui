#include <QApplication>
#include "../curveanalyzer.h"

int main(int argc, char *argv[])
{
	QApplication app(argc, argv);

	CurveAnalyzer w("a.jpg");
	w.show();

	return app.exec();
}
