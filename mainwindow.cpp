#include "mainwindow.h"
#include "ui_mainwindow.h"

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
    PathSearchWindow* window=new PathSearchWindow;
    window->show();
}

void MainWindow::on_fareSearchButto_clicked()
{
    this->hide();
    FareSearchWindow* window=new FareSearchWindow;
    window->show();
}
