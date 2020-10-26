#pragma once
#include "CPoint.h"
#include "CShapeDecorator.h"

class CCircle : public CShapeDecorator
{
public:
	CCircle(std::shared_ptr<IShape>&& shape, int x, int y, int radius)
		: CShapeDecorator(move(shape)),
		center(x, y),
		radius(radius)
	{
		circle.setRadius(radius);
		circle.setPosition(x, y);
	};

	double CalcPerim() override;
	double CalcSquare() override;
	std::string GetType() const override;

	bool CheckClick(int x, int y) override;
	CPoint GetCenter() const override;
	void MoveShape(int x, int y, sf::RenderWindow& window) override;
	void Draw(sf::RenderWindow& window) override;
	void DeleteBorder() override;

private:
	sf::CircleShape circle;
	CPoint center;
	int radius;
	std::string type = "Circle";
};

