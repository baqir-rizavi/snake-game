#pragma once
#include "point.h"
#include <ctime>
#include <cstdlib>

class fruit
{
	point position;
	int width;
	int height;
public:
	fruit(int w, int h) : width(w), height(h)
	{
		srand(time(0));
		position.x = rand() % (width-2) + 1;
		position.y = rand() % (height-2) + 1;
	}
	void reset()
	{
		position.x = rand() % (width-2) + 1;
		position.y = rand() % (height-2) + 1;
	}
	friend class game;
};