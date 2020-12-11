#pragma once

#include "Path.h"

#include<qvector.h>

class PriorityQueue {
public:

	PriorityQueue();
	~PriorityQueue();

	void push(const Path& path);
	Path pop();
	Path at(int num);
	
	bool empty();

private:
	
	QVector<Path> heap;
	int size;

};