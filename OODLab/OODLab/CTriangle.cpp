#include "CTriangle.h"

double CTriangle::CalcPerim()
{
	double a1 = sqrt(pow(p2.GetX() - p1.GetX(), 2) + pow(p2.GetY() - p1.GetY(), 2));
	double a2 = sqrt(pow(p3.GetX() - p2.GetX(), 2) + pow(p3.GetY() - p2.GetY(), 2));
	double a3 = sqrt(pow(p3.GetX() - p1.GetX(), 2) + pow(p3.GetY() - p1.GetY(), 2));
	return a1 + a2 + a3;
}

double CTriangle::CalcSquare()
{
	double a1 = sqrt(pow(p2.GetX() - p1.GetX(), 2) + pow(p2.GetY() - p1.GetY(), 2));
	double a2 = sqrt(pow(p3.GetX() - p2.GetX(), 2) + pow(p3.GetY() - p2.GetY(), 2));
	double a3 = sqrt(pow(p3.GetX() - p1.GetX(), 2) + pow(p3.GetY() - p1.GetY(), 2));
	double p = GetPerim() / 2;
	return sqrt(p * (p - a1) * (p - a2) * (p - a3));
}

std::string CTriangle::GetType() const
{
	return type;
}

void CTriangle::Draw(sf::RenderWindow& window)
{
	sf::ConvexShape triangle;
	triangle.setFillColor(sf::Color(0xFF, 0, 0xFF));
	//triangle.setPosition(300, 300);
	triangle.setPointCount(3);
	sf::Vector2f vect(p1.GetX(), p1.GetY());
	triangle.setPoint(0, vect);

	sf::Vector2f vect2(p2.GetX(), p2.GetY());
	triangle.setPoint(1, vect2);

	sf::Vector2f vect3(p3.GetX(), p3.GetY());
	triangle.setPoint(2, vect3);
	
	/*triangle.setPoint(0, {50, -20});
	triangle.setPoint(1, {50, 20});
	triangle.setPoint(2, {-100, 0});*/
	window.draw(triangle);
}
