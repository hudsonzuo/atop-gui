#ifndef _CURVEANALYZER_H_
#define _CURVEANALYZER_H_

#include <QtGui/QWidget>

class CurveAnalyzer : public QWidget
{
public:
    CurveAnalyzer(QWidget *parent = 0);
	void updateData(const QString &data);

private:
	CurveAnalyzer(const CurveAnalyzer &);
	CurveAnalyzer &operator=(const CurveAnalyzer &);
};

#endif /* _CURVEANALYZER_H_ */

















