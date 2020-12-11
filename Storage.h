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
#include<qfile.h>
#include<qtextstream.h>

class Storage
{
public:
	Storage();

	bool setFromStation(QString fromStation);	//dijkstra initialize
	QVector<QString> getPath(QString toStation);
	int getDistance(QString toStation);
	int getFare(QString toStation);
	QVector<QString> getLineNameList();		//��·�����б�
	QVector<int> getLineOrderList(int lineNum);	//��·վ������˳���б�

	~Storage();
private:
	ListGraph stationAdjacencyList;
	HashTable stationHashList;
	
	QVector<QString> lineNameList;
	QVector<QVector<int> > lineOrderList;

	Dijkstra stationPathList;
};