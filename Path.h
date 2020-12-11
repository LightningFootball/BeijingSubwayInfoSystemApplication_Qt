#pragma once

class Path
{
public:
	int fromStationNum;
	int distance;
	int toStationNum;

	Path();
	Path(int fromStation, int distance, int toStationNum);
	
	Path operator=(const Path& otherPath);
	bool operator<(const Path& otherPath);
	bool operator<=(const Path& otherPath);
	bool operator>(const Path& otherPath);
	bool operator>=(const Path& otherPath);

	~Path();

private:

};