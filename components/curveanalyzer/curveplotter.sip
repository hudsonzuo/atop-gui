%Module CurvePlotter

%Import QtCore/QtCoremod.sip
%Import QtGui/QtGuimod.sip

class CurvePlotter : public QWidget
{

%TypeHeaderCode
#include "curveplotter.h"
%End

public:
		enum { MAX_LENGTH = 300, MAX_PERCENT = 100 };
		CurvePlotter(QWidget *parent = 0);

protected:
		void paintEvent(QPaintEvent *e);
		void resizeEvent(QResizeEvent *e);

private:
		qreal x(qreal second);
		qreal y(qreal percent);
private:
		QRectF showArea_;
};