#ifndef _CURVEANALYZER_H_
#define _CURVEANALYZER_H_

#include <QtGui/QWidget>

class CurvePlotter;

class CurveAnalyzer : public QWidget
{
public:
	static bool registerToSystem(QString version);
    CurveAnalyzer(QWidget *parent = 0);
	void updateData(const QString &data);

protected:
	void resizeEvent(QResizeEvent *e);
	
private:
	CurvePlotter *curvePlotter_;
	
private:
	CurveAnalyzer(const CurveAnalyzer &);
	CurveAnalyzer &operator=(const CurveAnalyzer &);
};

#endif /* _CURVEANALYZER_H_ */

















