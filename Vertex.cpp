#include "Vertex.h"

Vertex::Vertex() {
	this->firstArc = nullptr;
}

bool Vertex::appendArc(Arc* arc)
{
	if (firstArc == nullptr)
	{
		firstArc = arc;
		return true;
	}
	Arc* buoy;		//buoy ����
	buoy = firstArc;
	while (buoy->nextArc != nullptr)
	{
		buoy = buoy->nextArc;
	}
	buoy->nextArc = arc;
	return true;
}

Arc Vertex::getArc(int arcNum)		//getArc start from arc[0]
{
	Arc retArc(-1, -1);
	if (firstArc == nullptr)
	{
		return retArc;
	}
	Arc* buoy = firstArc;		//buoy ����
	for (int i = 0; i < arcNum; ++i)
	{
		if (buoy->nextArc == nullptr)
		{
			return retArc;
		}
		buoy = buoy->nextArc;
	}
	retArc = *buoy;
	return retArc;
}

bool Vertex::copyFirstArc(Arc* firstArc)	//��ȫ��ֵ�Ĺ��캯��
{
	this->firstArc = firstArc;
	return true;
}

bool Vertex::newFirstArc(const Vertex& otherVertex)	//�������
{
	if (this != &otherVertex && 0 != &otherVertex)
	{
		this->firstArc = new Arc(*otherVertex.firstArc);
	}
	return true;
}

Vertex::~Vertex()
{
}