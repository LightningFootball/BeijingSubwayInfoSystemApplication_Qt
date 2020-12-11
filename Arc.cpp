#include "Arc.h"

Arc::Arc(int stationNum, int distance)	//���ڽӵĹ��캯��
{
	this->stationNum = stationNum;
	this->distance = distance;
}

Arc::Arc(int stationNum, int distance, Arc* nextArc)	//���ڽӡ���ȫ��ֵ�Ĺ��캯��
{
	this->stationNum = stationNum;
	this->distance = distance;
	this->nextArc = nextArc;
}

Arc::Arc(const Arc& otherArc)	//�������캯��
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