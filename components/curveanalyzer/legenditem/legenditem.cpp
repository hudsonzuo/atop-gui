#include "legenditem.h"
#include <QtGui/QLabel>
#include <QtGui/QResizeEvent>
#include "colorblock.h"

LegendItem::LegendItem(const QColor &color,
					   const QString &label,
					   QWidget *parent)
	: QWidget(parent)
{
	colorBlock_ = new ColorBlock(color, this);
	label_ = new QLabel(label, this);

	colorBlock_->setFixedSize(22, 22);
	colorBlock_->move(0, 0);
	label_->move(25, 0);
	label_->setFixedHeight(23);
	
	
	QPalette p = palette();
	p.setColor(QPalette::Window, Qt::black);
	p.setColor(QPalette::WindowText, Qt::green);
	setPalette(p);

	setToolTip(label);
}

void LegendItem::resizeEvent(QResizeEvent *event)
{
	label_->setMinimumWidth(event->size().width() - 25);
}




















