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
	//从stationHash起始节点开始，访问list，看其可到达的点，加入buf，得到最小节点
    //看其到达编号，将上一站点数据拷贝过来，append上这个点。
	//递归，直到距离除了起始节点非零
	for (int i = 0; i < stationVolume - 1; i++)		//dijkstra算法计算得路径数
	{
		PriorityQueue stationBuffer;	//单次路径拓展计算初始化一次优先队列
		for (int j = 0; j < dijkstraList.size(); j++)	//单次路径拓展需要遍历全部节点
		{
            if (dijkstraList[j][0] != -1)	//如果站点已经访达
			{
				//Arc getArc(int arcNum);
				if (list->list[j].getArc(0).stationNum != -1)	//站点有至少一个节点，该条件可能不必要
				{
					for (int k = 0; list->list[j].getArc(k).stationNum != -1; k++)	//得到所有边
					{
						//j->from,dis->arc.dis,to->arc.stationNum
						if (dijkstraList[list->list[j].getArc(k).stationNum][0] != -1)
						{
							continue;
						}
						Path temp;
						temp.fromStationNum = j;
                        temp.distance = list->list[j].getArc(k).distance+dijkstraList[temp.fromStationNum][0];  //dijkstra算法不要理解错！！！
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
