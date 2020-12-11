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

class Dijkstra		//�����ʱ����¼��վ��dijkstra��������ڿɰ�װΪһ���洢����վ��dijkstra�������
{
public:
	QVector<QVector<int>> dijkstraList;		//��һ�м�¼�ܾ�����Ϣ���м�¼·����Ϣ����ֵΪ�յ�Hash

	Dijkstra();

	void setSpace(int size,int stationVolume);

	void operate(ListGraph* list, int stationHash);
	void reset();

	~Dijkstra();

private:
	int stationVolume;
};