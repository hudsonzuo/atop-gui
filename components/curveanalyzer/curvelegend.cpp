#include "curvelegend.h"
#include <QtGui/QPainter>
#include <QtGui/QColor>

CurveLegend::CurveLegend(QWidget *parent)
    : QWidget(parent)
{
	QPalette palette(this->palette());
	palette.setColor(QPalette::Window, Qt::black);
	setPalette(palette);
	colors_ = QColor::colorNames();
	colors_.removeOne("black");
}

void CurveLegend::paintEvent(QPaintEvent *)
{
	QPainter painter(this);

	painter.setPen(QColor(255, 255, 255, 125));
	painter.drawRect(this->rect().adjusted(4, 12, -2, -28));
}

void CurveLegend::addItem(const QString &name)
{
	itemVector_.append(name);
}



















