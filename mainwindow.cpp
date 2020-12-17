#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
	connect(fareSearchWindow,SIGNAL(fareWindowCloseSignal()),this,SLOT(windowShow()));
	connect(pathSearchWindow,SIGNAL(pathSearchWindowClosedSignal()),this,SLOT(windowShow()));
	connect(mapWindow,SIGNAL(mapWindowReturned()),this,SLOT(windowShow()));
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pathSearchButton_clicked()
{
    this->hide();
	//PathSearchWindow* window=new PathSearchWindow;
	pathSearchWindow->show();
}

void MainWindow::on_fareSearchButto_clicked()
{
    this->hide();
	//FareSearchWindow* window=new FareSearchWindow;
	fareSearchWindow->show();
}

void MainWindow::on_mapSearchButton_clicked()
{
	this->hide();
	//MapWindow* window=new MapWindow;
	mapWindow->show();
}

void MainWindow::on_actionAbout_triggered()
{
	//AboutWindow* window= new AboutWindow;
	aboutWindow->show();
}

void MainWindow::windowShow()
{
	this->show();
}
