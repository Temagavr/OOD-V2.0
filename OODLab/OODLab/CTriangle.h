#pragma once
#include "CShapeDecorator.h"
class CTriangle : public CShapeDecorator
{
public:

	CTriangle(std::unique_ptr<IShape>&& shape, int x1, int y1, int x2, int y2, int x3, int y3)
		: p1(x1, y1),
		p2(x2, y2),
		p3(x3, y3),
		CShapeDecorator(move(shape))
	{};

	double CalcPerim() override;
	double CalcSquare() override;
	std::string GetType() const;

	void Draw(sf::RenderWindow& window) override;

private:
	std::string type = "Triangle";
	CPoint p1;
	CPoint p2;
	CPoint p3;
};

