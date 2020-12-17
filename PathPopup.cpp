#include "PathPopup.h"
#include "ui_PathPopup.h"

PathPopup::PathPopup(QWidget *parent) :
	QDialog(parent),
	ui(new Ui::PathPopup)
{
	ui->setupUi(this);
}

void PathPopup::setToStation(QString string)
{
	pathStringListModel.setStringList(database.getPath(string));
	ui->listView->setModel(&pathStringListModel);
	//ui->listView->setItemAlignment()
}

PathPopup::~PathPopup()
{
	delete ui;
}

void PathPopup::on_okButton_clicked()
{
	this->hide();
}
