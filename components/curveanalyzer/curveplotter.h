#ifndef _CURVEPLOTTER_H_
#define _CURVEPLOTTER_H_

#include <QtGui/QWidget>
#include <QtCore/QRect>

class QPaintEvent;

class CurvePlotter : public QWidget
{
public:
	enum { MAX_LENGTH = 300, MAX_PERCENT = 100 };
    CurvePlotter(QWidget *parent = 0);

protected:
	void paintEvent(QPaintEvent *e);
	void resizeEvent(QResizeEvent *e);

private:
	qreal x(qreal second);
	qreal y(qreal percent);
	
private:
	QRectF showArea_;
};

#endif /* _CURVEPLOTTER_H_ */

















