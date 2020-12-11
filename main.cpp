#include "mainwindow.h"

#include <QApplication>

#include "Storage.h"

Storage database;

int main(int argc, char *argv[])
{
    extern Storage database;

    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    return a.exec();
}
