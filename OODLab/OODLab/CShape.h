#pragma once

#include "IShape.h"

class CShape : public IShape
{
public:
	
	void SetPerim(double per) override
	{
		perimeter = per;
	}

	void SetSquare(double sq) override
	{
		square = sq;
	}

	double GetPerim() const override
	{
		return perimeter;
	}

	double GetSquare() const override
	{
		return square;
	}

	void Accept(IVisitor& visitor) override
	{}

private:
	double perimeter = 0;
	double square = 0;
};