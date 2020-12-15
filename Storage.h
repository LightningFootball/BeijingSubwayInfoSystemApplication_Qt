#pragma once

#include "ListGraph.h"

#include "Arc.h"
#include "HashTable.h"
#include "Hash.h"
#include "PriorityQueue.h"
#include "Dijkstra.h"

#include <string>
#include <fstream>
#include <stdio.h>

#include<qstring.h>
#include<qstringlist.h>
#include<qfile.h>
#include<qtextstream.h>
#include "QColor"

class Storage
{
public:
	Storage();

    int setFromStation(QString fromStation);	//dijkstra initialize
    QStringList getPath(QString toStation);
	int getDistance(QString toStation);
	int getFare(QString toStation);
    QStringList getLineNameList();		//线路名称列表
    QStringList getLineStationOrderList(QString lineName);	//线路站点名称顺序列表
	QStringList getLineStationOrderList(int lineNum);		//线路站点名称顺序列表
	int getLineStationNum(int lineNum); //指定线路站点数量
	int getTotalLineNum();      //总线路数量
	QColor getLineColor(int lineNum);

	~Storage();
private:
	ListGraph stationAdjacencyList;
	HashTable stationHashList;
	
	QVector<QString> lineNameList;
    QVector<QVector<int>> lineStationOrderList;
	QVector<int> lineStationNumList;
	int totalLineNum;
	QVector<QColor> lineColorList;

	Dijkstra stationPathList;
};
