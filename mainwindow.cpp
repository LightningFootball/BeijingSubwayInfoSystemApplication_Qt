#include "mainwindow.h"
#include "ui_mainwindow.h"

#include "PathSearchWindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pathSearchButton_clicked()
{
    this->hide();
    PathSearchWindow* pathSearchWindow=new PathSearchWindow;
    pathSearchWindow->show();
}
