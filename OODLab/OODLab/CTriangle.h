#pragma once
#include "CShapeDecorator.h"
class CTriangle : public CShapeDecorator
{
public:

	CTriangle(std::shared_ptr<IShape>&& shape, int x1, int y1, int x2, int y2, int x3, int y3)
		: p1(x1, y1),
		p2(x2, y2),
		p3(x3, y3),
		CShapeDecorator(move(shape))
	{};

	double CalcPerim() override;
	double CalcSquare() override;
	std::string GetType() const;

	bool CheckClick(int x, int y) override;
	CPoint GetCenter() const override;
	void MoveShape(int x, int y, sf::RenderWindow& window) override;
	void Draw(sf::RenderWindow& window) override;
	void DeleteBorder() override;

private:
	sf::ConvexShape triangle;
	std::string type = "Triangle";
	CPoint center;
	CPoint p1;
	CPoint p2;
	CPoint p3;
};

