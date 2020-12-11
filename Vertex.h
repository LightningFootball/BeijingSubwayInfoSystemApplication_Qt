#pragma once

#include "Arc.h"

using namespace std;

class Vertex
{
public:
	Arc* firstArc = nullptr;

	Vertex();
	
	bool appendArc(Arc* arc);
	Arc getArc(int arcNum);
	
	bool copyFirstArc(Arc* firstArc);
	bool newFirstArc(const Vertex& otherVertex);
	
	~Vertex();
	
private:
	
};

