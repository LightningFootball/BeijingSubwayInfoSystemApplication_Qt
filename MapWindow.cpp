#include "MapWindow.h"
#include "ui_MapWindow.h"

MapWindow::MapWindow(QWidget *parent) :
	QWidget(parent),
	ui(new Ui::MapWindow)
{
	ui->setupUi(this);
	QImage map;
	map.load(":/Picture/Resorce/subway_map.jpg");
	QPixmap mapPix=QPixmap::fromImage(map);

	//ui->Picture->setSizePolicy(QSizePolicy::Ignored,QSizePolicy::Ignored);
	ui->Picture->setPixmap(mapPix);
	ui->Picture->setScaledContents(true);
}

MapWindow::~MapWindow()
{
	delete ui;
}

void MapWindow::on_pushButton_clicked()
{
	this->close();
	emit mapWindowReturned();
}
