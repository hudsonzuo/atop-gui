#include "curvelegend.h"
#include <QtGui/QPainter>
#include <QtGui/QColor>
#include <QtGui/QScrollArea>
#include <QtGui/QResizeEvent>
#include <QtGui/QVBoxLayout>
#include "legenditem.h"

CurveLegend::CurveLegend(QWidget *parent)
    : QWidget(parent)
{
	QPalette palette(this->palette());
	palette.setColor(QPalette::Window, Qt::black);
	setPalette(palette);
	colors_ = QColor::colorNames();
	colors_.removeOne("black");
	layout_ = new QVBoxLayout();
	container_ = new QWidget();
	container_->setLayout(layout_);
	scrollArea_ = new QScrollArea(this);
	scrollArea_->move(5, 13);
	scrollArea_->setWidget(container_);
	scrollArea_->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
	scrollArea_->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
}

QColor CurveLegend::addItem(const QString &name)
{
	QColor color = colors_.at(legendItemList_.size());
	LegendItem *li = new LegendItem(name, color);
	layout_->addWidget(li);
	legendItemList_.append(li);
	container_->resize(500, legendItemList_.size() * 35);
	return color;
}

void CurveLegend::resizeEvent(QResizeEvent *e)
{
	scrollArea_->resize(e->size() - QSize(7, 40));
}

















