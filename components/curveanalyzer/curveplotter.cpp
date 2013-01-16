#include "curveplotter.h"
#include <QtGui/QPainter>
#include <QtGui/QPaintEvent>
#include <QtGui/QFontMetrics>

CurvePlotter::CurvePlotter(QWidget *parent)
	: QWidget(parent)
{
	QPalette palette = this->palette();
	palette.setColor(QPalette::Window, Qt::black);
	setPalette(palette);
}

void CurvePlotter::paintEvent(QPaintEvent *e)
{
	QPainter painter(this);

	painter.setPen(QColor(255, 255, 255, 125));
	painter.drawRect(showArea_);
	QFont font;
	QFontMetrics fm(font);
	// draw x axis

	// draw y axis
	painter.setPen(Qt::white);
	int ax = 1;
	for (int i = 0; i < 101; i+= 10) {
		qreal ay = y(i);
		painter.drawText(QRectF(ax, ay-fm.height()/2, 40, 25),
							 Qt::AlignRight, QString("%1%").arg(i));
		painter.drawLine(46, ay, showArea_.left(), ay);
	}
}

void CurvePlotter::resizeEvent(QResizeEvent *e)
{
	showArea_ = this->rect().adjusted(50, 10, -1, -30);
}

qreal CurvePlotter::x(qreal second)
{
	qreal dx = (showArea_.width() / CurvePlotter::MAX_LENGTH) * second;
	return showArea_.left() + dx;
}

qreal CurvePlotter::y(qreal percent)
{
	qreal dy = (showArea_.height() / CurvePlotter::MAX_PERCENT) * percent;
	return showArea_.bottom() - dy;
}



















