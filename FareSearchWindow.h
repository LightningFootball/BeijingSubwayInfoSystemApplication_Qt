#pragma once

#include <QWidget>
#include "ui_FareSearchWindow.h"

#include "QStringListModel"
#include "qstringlist.h"
#include "qstring.h"

#include "QTableView"
#include "QStandardItemModel"
#include "QStandardItem"
#include "QList"
#include "QColor"

#include "Storage.h"

extern Storage database;

class FareSearchWindow : public QWidget
{
	Q_OBJECT

public:
    QStringListModel lineStringListModel;
    QStringListModel stationStringListModel;

    QStandardItemModel tableModel;

	FareSearchWindow(QWidget *parent = Q_NULLPTR);
	~FareSearchWindow();

private slots:
    void on_lineSwitch_currentIndexChanged(const QString &arg1);

	void on_stationSwitch_currentTextChanged(const QString &arg1);

private:
	Ui::FareSearchWindow ui;
};
