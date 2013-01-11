%Module CurveAnalyzer

%Import QtGui/QtGuimod.sip

class CurveAnalyzer : public QWidget
{

public:
	CurveAnalyzer(QWidget *parent = 0);
	void updateData(const QString &data);

private:
	CurveAnalyzer(const CurveAnalyzer &);
	CurveAnalyzer &operator=(const CurveAnalyzer &);
};