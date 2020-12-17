#include "AboutWindow.h"
#include "ui_AboutWindow.h"

AboutWindow::AboutWindow(QWidget *parent) :
	QWidget(parent),
	ui(new Ui::AboutWindow)
{
	ui->setupUi(this);
	Qt::WindowFlags flag = windowFlags();
	setWindowFlags(flag | Qt::WindowStaysOnTopHint);
}

AboutWindow::~AboutWindow()
{
	delete ui;
}
