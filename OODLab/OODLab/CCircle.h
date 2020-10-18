#pragma once
#include "CPoint.h"
#include "CShapeDecorator.h"

class CCircle : public CShapeDecorator
{
public:
	CCircle(std::unique_ptr<IShape>&& shape, int x, int y, int radius)
		: CShapeDecorator(move(shape)),
		center(x, y),
		radius(radius)
	{};

	double CalcPerim() override;
	double CalcSquare() override;
	CPoint GetCenter() const;
	std::string GetType() const override;

	void Draw(sf::RenderWindow& window) override;

private:
	CPoint center;
	int radius;
	std::string type = "Circle";
};

