#pragma once

#include "ListGraph.h"
#include "PriorityQueue.h"
#include "Arc.h"
#include "HashTable.h"
#include "Path.h"

#include <qvector.h>
#include <string>
#include <stdio.h>
#include <qstring.h>

class Dijkstra		//该类此时仅记录单站点dijkstra结果，后期可包装为一个存储所有站点dijkstra结果的类
{
public:
	QVector<QVector<int>> dijkstraList;		//第一列记录总距离信息，行记录路线信息，行值为终点Hash

	Dijkstra();

	void setSpace(int size,int stationVolume);

	void operate(ListGraph* list, int stationHash);
	void reset();

	~Dijkstra();

private:
	int stationVolume;
};