#pragma once
#include "CShapeDecorator.h"
class CRectangle : public CShapeDecorator
{
public:

	CRectangle(std::unique_ptr<IShape>&& shape, int x1, int y1, int x2, int y2) :
		p1(x1, y1),
		p2(x2, y2),
		CShapeDecorator(move(shape))
	{};

	double CalcPerim() override;
	double CalcSquare() override;
	std::string GetType() const;

	void Draw(sf::RenderWindow& window) override;

private:
	std::string type = "Rectangle";
	CPoint p1;
	CPoint p2;
};

