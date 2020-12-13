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
    dijkstraList[stationHash][0]=0;
	//��stationHash��ʼ�ڵ㿪ʼ������list������ɵ���ĵ㣬����buf���õ���С�ڵ�
    //���䵽���ţ�����һվ�����ݿ���������append������㡣
	//�ݹ飬ֱ�����������ʼ�ڵ����
	for (int i = 0; i < stationVolume - 1; i++)		//dijkstra�㷨�����·����
	{
		PriorityQueue stationBuffer;	//����·����չ�����ʼ��һ�����ȶ���
		for (int j = 0; j < dijkstraList.size(); j++)	//����·����չ��Ҫ����ȫ���ڵ�
		{
            if (dijkstraList[j][0] != -1)	//���վ���Ѿ��ô�
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
                        temp.distance = list->list[j].getArc(k).distance+dijkstraList[temp.fromStationNum][0];  //dijkstra�㷨��Ҫ��������
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

        dijkstraList[stationBuffer.at(0).toStationNum][0] = stationBuffer.at(0).distance;
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
