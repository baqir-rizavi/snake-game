#pragma once

class point
{
private:
	int x, y;
public:
	point() : point (5,5)
	{}
	point(int i, int j) : x(i), y(j)
	{}
	bool operator==(const point& p)
	{
		if (x == p.x && y == p.y)
		{
			return true;
		}
		else
		{
			return false;
		}
	}
	friend class fruit;
	friend class snake;
	friend class game;
};
