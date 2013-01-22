#include "curveanalyzer.h"
#include <QtGui/QResizeEvent>
#include "curveplotter.h"
#include "curvelegend.h"

bool CurveAnalyzer::registerToSystem(QString version)
{
	return true;
}

CurveAnalyzer::CurveAnalyzer(QWidget *parent)
	: QWidget(parent)
{
	curvePlotter_ = new CurvePlotter(this);
	curveLegend_ = new CurveLegend(this);
	
	curvePlotter_->move(2, 2);

	setMinimumSize(640, 400);
	QPalette palette(this->palette());
	palette.setColor(QPalette::Window, Qt::black);
	setPalette(palette);
}

void CurveAnalyzer::updateData(const QString &data)
{
	
}

void CurveAnalyzer::resizeEvent(QResizeEvent *e)
{
	QSize size = e->size();
	curvePlotter_->resize(size - QSize(150, 0));
	curveLegend_->move(size.width()-150, 0);
	curveLegend_->resize(150, size.height());
}














