#pragma once

#include <iostream>
#include "point.h"

class snake
{
	point tail[100];
	int length;
public:
	snake(int w, int h) : length(1)
	{
		*tail = point(w, h);
	}
	friend class game;
};