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
	Arc* buoy;		//buoy 浮标
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
	Arc* buoy = firstArc;		//buoy 浮标
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

bool Vertex::copyFirstArc(Arc* firstArc)	//完全赋值的构造函数
{
	this->firstArc = firstArc;
	return true;
}

bool Vertex::newFirstArc(const Vertex& otherVertex)	//深拷贝函数
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