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
    QStringList getLineNameList();		//��·�����б�
    QStringList getLineStationOrderList(QString lineName);	//��·վ������˳���б�
	QStringList getLineStationOrderList(int lineNum);		//��·վ������˳���б�
	int getLineStationNum(int lineNum); //ָ����·վ������
	int getTotalLineNum();      //����·����
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
