#pragma once

#include <QWidget>
#include "ui_FareSearchWindow.h"

class FareSearchWindow : public QWidget
{
	Q_OBJECT

public:
	FareSearchWindow(QWidget *parent = Q_NULLPTR);
	~FareSearchWindow();

private:
	Ui::FareSearchWindow ui;
};
