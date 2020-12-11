#include "ListGraph.h"

ListGraph::ListGraph()
{
	list.resize(10);
}

ListGraph::ListGraph(int vertexNum)
{
	list.resize(vertexNum);
}

int ListGraph::size()
{
	return list.size();
}

void ListGraph::resize(int size)
{
	list.resize(size);
}

void ListGraph::insert(int fromStationNum, int toStationNum, int distance)
{
	//判断插入位置是否越界
	while (fromStationNum >= list.size())
	{
		resize(this->size() / 0.75);
	}

	//插入
	Arc* arc = new Arc(toStationNum, distance);
	list[fromStationNum].appendArc(arc);

}

ListGraph::~ListGraph()
{

}