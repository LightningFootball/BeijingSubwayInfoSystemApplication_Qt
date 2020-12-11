#include "PriorityQueue.h"

PriorityQueue::PriorityQueue()
{
	size = 0;
}


PriorityQueue::~PriorityQueue()
{

}


void PriorityQueue::push(const Path& path)
{
	int i = size++;
	heap.append(path);
	while (i > 0) {
		int father = (i - 1) / 2;
		if (heap[father] <= path)
		{
			break;
		}
		heap[i] = heap[father];
		i = father;
	}
	heap[i] = path;
}


Path PriorityQueue::pop()
{
	Path ret = heap[0];
	Path x = heap[--size];
	int i = 0;
	while (i * 2 + 1 < size) {
		int a = i * 2 + 1, b = i * 2 + 2;
		if (b < size && heap[b] < heap[a])
		{
			a = b;
		}
		if (x <= heap[a])
		{
			break;
		}
		heap[i] = heap[a];
		i = a;
	}
	heap[i] = x;
	heap.pop_back();
	return ret;
}


Path PriorityQueue::at(int num)
{
	return heap[num];
}


bool PriorityQueue::empty()
{
	return size == 0;
}