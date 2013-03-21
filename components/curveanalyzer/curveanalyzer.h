#ifndef _CURVEANALYZER_H_
#define _CURVEANALYZER_H_

#include <QtGui/QWidget>
#include <QtCore/QByteArray>
#include <QtCore/QMap>

QT_BEGIN_NAMESPACE
class QPaintEvent;
QT_END_NAMESPACE

class CurvePlotter;
class CurveLegend;

class CurveAnalyzer : public QWidget
{
public:
	static bool registerToSystem(QString version);
    CurveAnalyzer(QWidget *parent = 0);
	void updateData(const QMap<QString, int> &data);

protected:
	void resizeEvent(QResizeEvent *event);
	void paintEvent(QPaintEvent *event); 
		
private:
	CurvePlotter *curvePlotter_;
	CurveLegend  *curveLegend_;
	
private:
	CurveAnalyzer(const CurveAnalyzer &);
	CurveAnalyzer &operator=(const CurveAnalyzer &);
};

#endif /* _CURVEANALYZER_H_ */

















