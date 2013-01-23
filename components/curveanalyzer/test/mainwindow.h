#ifndef _MAINWINDOW_H_
#define _MAINWINDOW_H_

#include <QtGui/QMainWindow>

class QTabWiget;

class MainWindow : public QMainWindow
{
public:
	MainWindow(QWidget *parent = 0);
	void addPage(QWidget *page, const QString &label);

protected:
	void resizeEvent(QResizeEvent *e);
	
private:
	QTabWidget *tabWidget_;
	
private:
	MainWindow(const MainWindow &);
	MainWindow &operator=(const MainWindow &);
};

#endif /* _MAINWINDOW_H_ */

















