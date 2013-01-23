#include "mainwindow.h"
#include <QtGui/QTabWidget>
#include <QtGui/QResizeEvent>

MainWindow::MainWindow(QWidget *parent)
	: QMainWindow(parent)
{
	tabWidget_ = new QTabWidget(this);
}

void MainWindow::addPage(QWidget *page, const QString &label)
{
	tabWidget_->addTab(page, label);
}

void MainWindow::resizeEvent(QResizeEvent *e)
{
	tabWidget_->resize(e->size());
}



















