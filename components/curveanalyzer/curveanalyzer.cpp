#include "curveanalyzer.h"
#include <QtGui/QResizeEvent>
#include "curveplotter.h"

bool CurveAnalyzer::registerToSystem(QString version)
{
	return true;
}

CurveAnalyzer::CurveAnalyzer(QWidget *parent)
	: QWidget(parent)
{
	curvePlotter_ = new CurvePlotter(this);
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
	curvePlotter_->resize(e->size() - QSize(150, 0));
}














