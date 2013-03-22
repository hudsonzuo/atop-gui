// Define the SIP wrapper to the CurveAnalyzer library
%Module(name=CurveAnalyzer)

%Import QtGui/QtGuimod.sip
%Import QtCore/QtCoremod.sip

%include <std_map.i>

%template(map_string_int) QMap<string, int>;

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
	void updateData(const QMap<QString, int> &data);

protected:
	void resizeEvent(QResizeEvent *event);
	void paintEvent(QPaintEvent *event);
	
private:
	CurveAnalyzer(const CurveAnalyzer &);
	CurveAnalyzer &operator=(const CurveAnalyzer &);
};
