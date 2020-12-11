#pragma once

#include <QWidget>
#include "ui_PathSearchWindow.h"

#include <QStringListModel>

#include "Storage.h"

extern Storage database;

class PathSearchWindow : public QWidget
{
	Q_OBJECT

public:
    QStringListModel stringListModel;

	PathSearchWindow(QWidget *parent = Q_NULLPTR);
	~PathSearchWindow();

private:
	Ui::PathSearchWindow ui;

private slots:
	//fromLineEdit
	
    void on_exitButton_clicked();
    void on_fromLineEdit_editingFinished();
    void on_toLineEdit_editingFinished();
    void on_processButton_clicked();
};
