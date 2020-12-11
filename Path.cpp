#include "Path.h"

Path::Path()
{
	fromStationNum = -1;
	distance = -1;
	toStationNum = -1;
}

Path::Path(int fromStationNum, int distance, int toStationNum)
{
	this->fromStationNum = fromStationNum;
	this->distance = distance;
	this->toStationNum = toStationNum;
}

Path Path::operator=(const Path& otherPath)
{
	this->fromStationNum = otherPath.fromStationNum;
	this->distance = otherPath.distance;
	this->toStationNum = otherPath.toStationNum;

	return *this;
}

bool Path::operator<(const Path& otherPath)
{
	if (this->distance < otherPath.distance)
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool Path::operator<=(const Path& otherPath)
{
	if (this->distance <= otherPath.distance)
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool Path::operator>(const Path& otherPath)
{
	if (this->distance > otherPath.distance)
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool Path::operator>=(const Path& otherPath)
{
	if (this->distance >= otherPath.distance)
	{
		return true;
	}
	else
	{
		return false;
	}
}

Path::~Path()
{
}