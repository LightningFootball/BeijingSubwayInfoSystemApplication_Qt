QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# The following define makes your compiler emit warnings if you use
# any Qt feature that has been marked deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS
RC_FILE += data.rc

# You can also make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    AboutWindow.cpp \
    Arc.cpp \
    Dijkstra.cpp \
    FareSearchWindow.cpp \
    Hash.cpp \
    HashTable.cpp \
    InvalidInputDialog.cpp \
    ListGraph.cpp \
    MapWindow.cpp \
    Path.cpp \
    PathSearchWindow.cpp \
    PriorityQueue.cpp \
    Storage.cpp \
    Vertex.cpp \
    main.cpp \
    mainwindow.cpp

HEADERS += \
    AboutWindow.h \
    Arc.h \
    DataProcess.h \
    Dijkstra.h \
    FareSearchWindow.h \
    Hash.h \
    HashTable.h \
    InvalidInputDialog.h \
    ListGraph.h \
    MapWindow.h \
    Path.h \
    PathSearchWindow.h \
    PriorityQueue.h \
    Storage.h \
    Vertex.h \
    mainwindow.h

FORMS += \
    AboutWindow.ui \
    FareSearchWindow.ui \
    InvalidInputDialog.ui \
    MapWindow.ui \
    PathSearchWindow.ui \
    mainwindow.ui

TRANSLATIONS += \
    BeijingSubwayInfoSystemApplication_Qt_zh_CN.ts

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    BeijingSubwayInfoSystemApplication.qrc

DISTFILES += \
	data.rc
