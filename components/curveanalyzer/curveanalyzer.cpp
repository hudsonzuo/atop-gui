#include "curveanalyzer.h"
#include <QtGui/QResizeEvent>
#include <QtGui/QPaintEvent>
#include <QtGui/QPainter>
#include <QtCore/QDebug>
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
}

void CurveAnalyzer::updateData(const std::map<QString, int> &data)
{
	std::map<QString, int>::const_iterator it;
	for (it = data.begin(); it != data.end(); ++it) {
	 	curveLegend_->addItem((*it).first);
	}
}

void CurveAnalyzer::resizeEvent(QResizeEvent *event)
{
	QSize size = event->size();
	curvePlotter_->resize(size - QSize(150, 0));
	curveLegend_->move(size.width()-150, 0);
	curveLegend_->resize(150, size.height());
}

void CurveAnalyzer::paintEvent(QPaintEvent *)
{
	QPainter painter(this);
	painter.fillRect(this->rect(), Qt::black);
}





