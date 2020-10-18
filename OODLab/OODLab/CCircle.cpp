#include "CCircle.h"

double CCircle::CalcPerim()
{
    return 2 * 3.14 * radius;
}

double CCircle::CalcSquare()
{
    return 3.14 * pow(radius, 2);
}

CPoint CCircle::GetCenter() const
{
    return center;
}

std::string CCircle::GetType() const
{
    return type;
}

void CCircle::Draw(sf::RenderWindow& window)
{
    sf::CircleShape circle(radius);
    sf::Vector2f vect(center.GetX(), center.GetY());
    circle.setPosition(vect);

    circle.setFillColor(sf::Color(0x0, 0xFF, 0x0));

    window.draw(circle);
}
