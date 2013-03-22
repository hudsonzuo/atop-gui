
#include <QtGui/QApplication>
#include "../legenditem.h"

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

	LegendItem li("Chromium", Qt::red);
	li.resize(200, 50);
	li.show();
	
    return app.exec();
}


















