#pragma once
#include "CShapeDecorator.h"
class CRectangle : public CShapeDecorator
{
public:

	CRectangle(std::shared_ptr<IShape>&& shape, int x1, int y1, int x2, int y2) :
		p1(x1, y1),
		p2(x2, y2),
		CShapeDecorator(move(shape))
	{
		int a1 = p2.GetY() - p1.GetY();
		int a2 = p2.GetX() - p1.GetX();
		sf::Vector2f vect1(a1, a2);
		center.SetX(a1 / 2);
		center.SetY(a2 / 2);
		rectangle.setSize(vect1);
		rectangle.setPosition(a1 / 2, a2 / 2);
	};

	double CalcPerim() override;
	double CalcSquare() override;
	std::string GetType() const;

	CPoint GetCenter() const override;
	bool CheckClick(int x, int y) override;
	void MoveShape(int x, int y, sf::RenderWindow& window) override;
	void Draw(sf::RenderWindow& window) override;
	void DeleteBorder() override;

private:
	sf::RectangleShape rectangle;
	std::string type = "Rectangle";
	CPoint p1;
	CPoint p2;
	CPoint center;
};

