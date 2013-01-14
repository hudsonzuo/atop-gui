#ifndef _ATOP_WIDGET_H_
#define _ATOP_WIDGET_H_

#include <QtGui/QWidget>

class AtopWidget : public QWidget
{
public:
	virtual void updateData(const QString &) {}
	virtual ~AtopWidget() {}
		
protected:
    AtopWidget(QWidget *parent = 0) : QWidget(parent)
	{}
};

#endif /* _ATOP_WIDGET_H_ */















