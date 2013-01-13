%Module CurveAnalyzer

%Import QtGui/QtGuimod.sip

class CurveAnalyzer : public QWidget
{

%TypeHeaderCode
#include "curveanalyzer.h"
%End

public:
	static bool registerToSystem(QString version);
	CurveAnalyzer(QWidget *parent = 0);
	void updateData(const QString &data);

private:
	CurveAnalyzer(const CurveAnalyzer &);
	CurveAnalyzer &operator=(const CurveAnalyzer &);
};