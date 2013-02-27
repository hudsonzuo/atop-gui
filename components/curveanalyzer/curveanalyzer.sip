%Module CurveAnalyzer

%Import QtGui/QtGuimod.sip
%Import QtCore/QtCoremod.sip

class CurveAnalyzer : public QWidget
{

%TypeHeaderCode
#include "curveanalyzer.h"
#include "curveplotter.h"
#include "curvelegend.h"
%End

public:
	static bool registerToSystem(QString version);
	CurveAnalyzer(QWidget *parent = 0);
	void updateData(QByteArray data);

protected:
	void resizeEvent(QResizeEvent *event);
	void paintEvent(QPaintEvent *event);
	
private:
	CurveAnalyzer(const CurveAnalyzer &);
	CurveAnalyzer &operator=(const CurveAnalyzer &);
};