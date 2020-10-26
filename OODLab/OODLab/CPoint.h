#pragma once

class CPoint
{
public:
	CPoint() {};
	CPoint(int x, int y) :x(x), y(y) {};

	int GetX()
	{
		return x;
	}

	int GetY()
	{
		return y;
	}

	void SetX(int newX)
	{
		x = newX;
	}

	void SetY(int newY)
	{
		y = newY;
	}

	~CPoint() {};

private:
	int x = 0;
	int y = 0;
};