#include "PathSearchWindow.h"

#include "mainwindow.h"

PathSearchWindow::PathSearchWindow(QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);

}

PathSearchWindow::~PathSearchWindow()
{
}

void PathSearchWindow::on_exitButton_clicked()
{
    this->close();

}

void PathSearchWindow::on_fromLineEdit_editingFinished()
{
    database.setFromStation(ui.fromLineEdit->text());
}

void PathSearchWindow::on_toLineEdit_editingFinished()
{

}

void PathSearchWindow::on_processButton_clicked()
{
    stringListModel.setStringList(database.getPath(ui.toLineEdit->text()));
    ui.pathList->setModel(&stringListModel);
}
