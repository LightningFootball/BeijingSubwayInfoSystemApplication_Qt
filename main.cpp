#include "mainwindow.h"

#include <QApplication>

#include "Storage.h"

Storage database;

int main(int argc, char *argv[])
{
	//QTextCodec::setCodecForTr(QTextCodec::codecForName("GB18030"));

    extern Storage database;

    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    return a.exec();
}
