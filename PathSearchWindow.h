#pragma once

#include <QWidget>
#include "ui_PathSearchWindow.h"

#include <QStringListModel>
#include <qstring.h>

#include "InvalidInputDialog.h"

#include "Storage.h"

extern Storage database;

class PathSearchWindow : public QWidget
{
	Q_OBJECT

public:
    QStringListModel pathStringListModel;

    QStringListModel fromLineStringListModel;
    QStringListModel fromStationStringListModel;
    QStringListModel toLineStringListModel;
    QStringListModel toStationStringListModel;


	PathSearchWindow(QWidget *parent = Q_NULLPTR);
	~PathSearchWindow();

private:
	Ui::PathSearchWindow ui;

private slots:
	//fromLineEdit
	
    void on_exitButton_clicked();
    void on_processButton_clicked();
    void on_fuzzySearchRadioButton_toggled(bool checked);
    void on_accurateSearchRadioButton_toggled(bool checked);
    void on_fromLineSwitch_currentIndexChanged(const QString &arg1);
    void on_toLineSwitch_currentIndexChanged(const QString &arg1);
    void on_fromStationSwitch_currentIndexChanged(const QString &arg1);
    void on_toStationSwitch_currentIndexChanged(const QString &arg1);

signals:
	void pathSearchWindowClosedSignal();
};
