#include "Dijkstra.h"

Dijkstra::Dijkstra()
{
	stationVolume = 0;
}

void Dijkstra::setSpace(int size, int stationVolume)
{
	this->stationVolume = stationVolume;

	dijkstraList.resize(size);
	for (int i = 0; i < dijkstraList.size(); i++)
	{
		dijkstraList[i].resize(100);		//path length Maximum
	}
	for (int i = 0; i < dijkstraList.size(); i++)
	{
		for (int j = 0; j < dijkstraList[i].size(); j++)
		{
			dijkstraList[i][j] = -1;
		}
	}
}

void Dijkstra::operate(ListGraph* list, int stationHash)
{
	//initialize
	for (int i = 0; i < dijkstraList.size(); i++)		//initial station=stationHash
	{
		dijkstraList[i][1] = stationHash;
	}
	//��stationHash��ʼ�ڵ㿪ʼ������list������ɵ���ĵ㣬����buf���õ���С�ڵ�
	//���䵽����ţ�·������ͷ���յ����β��
	//��ʱ����ɷ��ʣ�ͷ��һ��0��һ���о��룩�����ɵ���㣬����buf������С�㣬
	//���䵽���ţ�����һվ�����ݿ���������append������㡣
	//�ݹ飬ֱ�����������ʼ�ڵ����
	for (int i = 0; i < stationVolume - 1; i++)		//dijkstra�㷨�����·����
	{
		PriorityQueue stationBuffer;	//����·����չ�����ʼ��һ�����ȶ���
		for (int j = 0; j < dijkstraList.size(); j++)	//����·����չ��Ҫ����ȫ���ڵ�
		{
			if (j == stationHash || dijkstraList[j][0] != -1)	//�ڵ��е���ʼվ��������ѷ��ʽڵ�
			{
				//Arc getArc(int arcNum);
				if (list->list[j].getArc(0).stationNum != -1)	//վ��������һ���ڵ㣬���������ܲ���Ҫ
				{
					for (int k = 0; list->list[j].getArc(k).stationNum != -1; k++)	//�õ����б�
					{
						//j->from,dis->arc.dis,to->arc.stationNum
						if (dijkstraList[list->list[j].getArc(k).stationNum][0] != -1)
						{
							continue;
						}
						Path temp;
						temp.fromStationNum = j;
						temp.distance = list->list[j].getArc(k).distance;
						temp.toStationNum = list->list[j].getArc(k).stationNum;
						stationBuffer.push(temp);
					}
				}
			}
		}
		//buffer->list
		//copy:from->to
		dijkstraList[stationBuffer.at(0).toStationNum] = dijkstraList[stationBuffer.at(0).fromStationNum];
		//to:append:buf[0]
		int appendLocation = 1;
		while (dijkstraList[stationBuffer.at(0).toStationNum][appendLocation] != -1)
		{
			++appendLocation;
		}
		dijkstraList[stationBuffer.at(0).toStationNum][appendLocation] = stationBuffer.at(0).toStationNum;
		//distance+=
		if (appendLocation == 2)
		{
			dijkstraList[stationBuffer.at(0).toStationNum][0] = 0;
		}
		dijkstraList[stationBuffer.at(0).toStationNum][0] += stationBuffer.at(0).distance;
	}
}

void Dijkstra::reset()
{
	for (int i = 0; i < dijkstraList.size(); i++)
	{
		for (int j = 0; j < dijkstraList[i].size(); j++)
		{
			dijkstraList[i][j] = -1;
		}
	}
}

Dijkstra::~Dijkstra()
{
}