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

class Storage
{
public:
	Storage();

	bool setFromStation(QString fromStation);	//dijkstra initialize
    QStringList getPath(QString toStation);
	int getDistance(QString toStation);
	int getFare(QString toStation);
	QVector<QString> getLineNameList();		//线路名称列表
	QVector<int> getLineOrderList(int lineNum);	//线路站点名称顺序列表

	~Storage();
private:
	ListGraph stationAdjacencyList;
	HashTable stationHashList;
	
	QVector<QString> lineNameList;
	QVector<QVector<int> > lineOrderList;

	Dijkstra stationPathList;
};
