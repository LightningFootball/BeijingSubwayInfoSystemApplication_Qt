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
#include "QBrush"
#include "QColor"

#include "QModelIndex"
#include "QVariant"

#include "PathPopup.h"

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
signals:
	void fareWindowCloseSignal();

private slots:
    void on_lineSwitch_currentIndexChanged(const QString &arg1);

	void on_stationSwitch_currentTextChanged(const QString &arg1);

	void on_returnButton_clicked();

	void on_fareTable_doubleClicked(const QModelIndex &index);

	private:
	Ui::FareSearchWindow ui;
};
