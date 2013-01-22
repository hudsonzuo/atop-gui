#ifndef _CURVELEGEND_H_
#define _CURVELEGEND_H_

#include <QtGui/QWidget>
#include <QtCore/QVector>

class QPaintEvent;

class CurveLegend : public QWidget
{
public:
    CurveLegend(QWidget *parent = 0);
	void addItem(const QString &name);

protected:
	void paintEvent(QPaintEvent *e);

private:
	QVector<QString> itemVector_;
	QStringList colors_;
	
private:
	CurveLegend(const CurveLegend &);
	CurveLegend &operator=(const CurveLegend &);
};

#endif /* _CURVELEGEND_H_ */

















