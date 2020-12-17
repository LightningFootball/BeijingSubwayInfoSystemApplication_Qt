#include "PathSearchWindow.h"

#include "mainwindow.h"

PathSearchWindow::PathSearchWindow(QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);

    //Ĭ��ʹ��ģ�����������Գ�ʼ���ؾ�ȷ����Combo Box
    ui.toLineSwitch->hide();
    ui.toStationSwitch->hide();
    ui.fromStationSwitch->hide();
    ui.fromLineSwitch->hide();

    //��ȷ������������
    fromLineStringListModel.setStringList(database.getLineNameList());
    toLineStringListModel.setStringList(database.getLineNameList());

    ui.fromLineSwitch->setModel(&fromLineStringListModel);
    ui.toLineSwitch->setModel(&toLineStringListModel);

    //��ȷ������ʾ��Ϣ����
}

PathSearchWindow::~PathSearchWindow()
{
}

void PathSearchWindow::on_exitButton_clicked()
{
	emit pathSearchWindowClosedSignal();
	this->close();
}


//������ʽѡ��
void PathSearchWindow::on_fuzzySearchRadioButton_toggled(bool checked)
{
    if(checked)
    {
        ui.toLineSwitch->hide();
        ui.toStationSwitch->hide();
        ui.fromStationSwitch->hide();
        ui.fromLineSwitch->hide();
        ui.processButton->show();
    }else
    {
        ui.toLineSwitch->show();
        ui.toStationSwitch->show();
        ui.fromStationSwitch->show();
        ui.fromLineSwitch->show();
    }
}

void PathSearchWindow::on_accurateSearchRadioButton_toggled(bool checked)
{
    if(checked)
    {
        ui.fromLineEdit->hide();
        ui.toLineEdit->hide();
        ui.processButton->hide();
    }else
    {
        ui.fromLineEdit->show();
        ui.toLineEdit->show();
    }
}


//ģ������
void PathSearchWindow::on_processButton_clicked()
{
    if(ui.fromLineEdit->text()==NULL||ui.toLineEdit->text()==NULL)
    {
        InvalidInputDialog* window=new InvalidInputDialog;
        window->show();
    }
    else
    {
        database.setFromStation(ui.fromLineEdit->text());
        pathStringListModel.setStringList(database.getPath(ui.toLineEdit->text()));
        ui.pathList->setModel(&pathStringListModel);
        ui.fare->setNum(database.getFare(ui.toLineEdit->text()));
    }

}


//��ȷ����
void PathSearchWindow::on_fromLineSwitch_currentIndexChanged(const QString &arg1)
{
    fromStationStringListModel.setStringList(database.getLineStationOrderList(arg1));
    ui.fromStationSwitch->setModel(&fromStationStringListModel);
}

void PathSearchWindow::on_toLineSwitch_currentIndexChanged(const QString &arg1)
{
    toStationStringListModel.setStringList(database.getLineStationOrderList(arg1));
    ui.toStationSwitch->setModel(&toStationStringListModel);
}

void PathSearchWindow::on_fromStationSwitch_currentIndexChanged(const QString &arg1)
{
    if(ui.fromStationSwitch->currentIndex()==-1)
    {
        ui.fromStationSwitch->setCurrentIndex(0);
    }
    database.setFromStation(ui.fromStationSwitch->currentText());

    if(ui.accurateSearchRadioButton->isChecked())
    {
        pathStringListModel.setStringList(database.getPath(ui.toStationSwitch->currentText()));
        ui.pathList->setModel(&pathStringListModel);
        ui.fare->setNum(database.getFare(ui.toStationSwitch->currentText()));
    }
}

void PathSearchWindow::on_toStationSwitch_currentIndexChanged(const QString &arg1)
{
    if(ui.fromStationSwitch->currentText()==arg1&&ui.accurateSearchRadioButton->isChecked())
    {
        InvalidInputDialog* window=new InvalidInputDialog;
        window->show();
    }
    else if(ui.toStationSwitch->currentIndex()==-1)
    {
        ui.toStationSwitch->setCurrentIndex(0);
    }
    else if(ui.accurateSearchRadioButton->isChecked())
    {
        pathStringListModel.setStringList(database.getPath(ui.toStationSwitch->currentText()));
        ui.pathList->setModel(&pathStringListModel);
        ui.fare->setNum(database.getFare(ui.toStationSwitch->currentText()));
    }
}
