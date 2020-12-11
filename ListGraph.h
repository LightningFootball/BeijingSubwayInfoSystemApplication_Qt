#pragma once

#include "Vertex.h"
#include "Arc.h"
#include "HashTable.h"

#include <qstring.h>
#include <qvector.h>

using namespace std;

class ListGraph		//���ڽӱ�����ñ���Ŀ������Ǩ����������Ŀ
{
public:
	ListGraph();
	ListGraph(int vertexNum);		//��ֵ����

	int size();
	void resize(int size);

	void insert(int fromStationNum,int toStationNum,int distance);

	QVector<Vertex> list;

	~ListGraph();
protected:
	

private:

};