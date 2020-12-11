#pragma once

class Arc
{
public:
	int stationNum = -1;
	int distance = -1;
	Arc* nextArc = nullptr;

	Arc(int stationNum, int distance);
	Arc(int stationNum, int distance, Arc* nextArc);
	Arc(const Arc& otherArc);
	~Arc();

private:

};