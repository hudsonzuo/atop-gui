#ifndef _LEGENDITEM_H_
#define _LEGENDITEM_H_

#include <QtGui/QWidget>

class QLabel;
class QResizeEvent;
class ColorBlock;

class LegendItem : public QWidget
{
public:
    LegendItem(const QString &label, const QColor &color, QWidget *parent = 0);

protected:
	void resizeEvent(QResizeEvent *event);
	
private:
	ColorBlock *colorBlock_;
	QLabel *label_;
};

#endif /* _LEGENDITEM_H_ */

















