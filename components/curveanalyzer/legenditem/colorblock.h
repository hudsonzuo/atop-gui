#ifndef _COLORBLOCK_H_
#define _COLORBLOCK_H_

#include <QtGui/QWidget>

class ColorBlock : public QWidget
{
public:
    ColorBlock(const QColor &color, QWidget *parent = 0);
	void setColor(const QColor &color);

protected:
	void paintEvent(QPaintEvent *event);

private:
	QColor color_;
	
private:
	ColorBlock(const ColorBlock &);
	ColorBlock &operator=(const ColorBlock &);
};

#endif /* _COLORBLOCK_H_ */




















