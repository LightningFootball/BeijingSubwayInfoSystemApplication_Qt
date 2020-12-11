#pragma once

#include "Vertex.h"
#include "Arc.h"
#include "HashTable.h"

#include <qstring.h>
#include <qvector.h>

using namespace std;

class ListGraph		//该邻接表仅适用本项目，不可迁移至其他项目
{
public:
	ListGraph();
	ListGraph(int vertexNum);		//赋值构造

	int size();
	void resize(int size);

	void insert(int fromStationNum,int toStationNum,int distance);

	QVector<Vertex> list;

	~ListGraph();
protected:
	

private:

};