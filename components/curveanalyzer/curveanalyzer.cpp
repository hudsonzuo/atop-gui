#include "curveanalyzer.h"
#include <QtGui/QResizeEvent>
#include <QtGui/QPaintEvent>
#include <QtGui/QPainter>
#include <QtCore/QMap>
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

void CurveAnalyzer::updateData(QByteArray data)
{
	bool ok;
	QVariantMap result = parser_.parse(&data, &ok).toMap();
	if (!ok) return;
	QMap<QString, QVariant>::const_iterator i = result.constBegin();
	while (i != result.constEnd()) {
		
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





