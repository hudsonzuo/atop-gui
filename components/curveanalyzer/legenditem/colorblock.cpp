#include "colorblock.h"
#include <QtGui/QPainter>

ColorBlock::ColorBlock(const QColor &color, QWidget *parent)
	: QWidget(parent), color_(color)
{}

void ColorBlock::paintEvent(QPaintEvent *)
{
	QPainter painter(this);

	QRectF rct = this->rect().adjusted(0, 0, -1, -1);
	painter.setPen(Qt::white);
	painter.fillRect(rct, color_);
	painter.drawRect(rct);
}

void ColorBlock::setColor(const QColor &color)
{
	color_ = color;
	update();
}



















