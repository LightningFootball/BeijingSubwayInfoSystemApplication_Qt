#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

#include "PathSearchWindow.h"
#include "FareSearchWindow.h"
#include "MapWindow.h"
#include "AboutWindow.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_pathSearchButton_clicked();

    void on_fareSearchButto_clicked();

	void on_mapSearchButton_clicked();

	void on_actionAbout_triggered();

	void windowShow();

	private:
    Ui::MainWindow *ui;

	PathSearchWindow* pathSearchWindow=new PathSearchWindow;
	FareSearchWindow* fareSearchWindow=new FareSearchWindow;
	MapWindow* mapWindow=new MapWindow;
	AboutWindow* aboutWindow= new AboutWindow;
};
#endif // MAINWINDOW_H
