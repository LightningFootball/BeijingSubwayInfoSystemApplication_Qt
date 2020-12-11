#include "Arc.h"

Arc::Arc(int stationNum, int distance)	//无邻接的构造函数
{
	this->stationNum = stationNum;
	this->distance = distance;
}

Arc::Arc(int stationNum, int distance, Arc* nextArc)	//有邻接、完全赋值的构造函数
{
	this->stationNum = stationNum;
	this->distance = distance;
	this->nextArc = nextArc;
}

Arc::Arc(const Arc& otherArc)	//拷贝构造函数
{
	if (this != &otherArc && 0 != &otherArc)
	{
		this->stationNum = otherArc.stationNum;
		this->distance = otherArc.distance;
		this->nextArc = otherArc.nextArc;
	}
}

Arc::~Arc()
{
}