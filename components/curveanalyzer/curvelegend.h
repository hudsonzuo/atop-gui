#ifndef _CURVELEGEND_H_
#define _CURVELEGEND_H_

#include <QtGui/QWidget>
#include <QtCore/QVector>

class QPaintEvent;
class QResizeEvent;
class QScrollArea;
class QVBoxLayout;
class LegendItem;

class CurveLegend : public QWidget
{
public:
    CurveLegend(QWidget *parent = 0);
	QColor addItem(const QString &name);

protected:
	void resizeEvent(QResizeEvent *e);

private:
	QStringList colors_;
	QList<LegendItem *> legendItemList_;
	QScrollArea *scrollArea_;
	QWidget *container_;
	QVBoxLayout *layout_;
	
private:
	CurveLegend(const CurveLegend &);
	CurveLegend &operator=(const CurveLegend &);
};

#endif /* _CURVELEGEND_H_ */

















