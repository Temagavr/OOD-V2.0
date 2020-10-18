#include "CRectangle.h"

double CRectangle::CalcPerim()
{
    double a1 = p2.GetY() - p1.GetY();
    double a2 = p2.GetX() - p1.GetX();
    return 2 * a1 + 2 * a2;
}

double CRectangle::CalcSquare()
{
    double a1 = p2.GetY() - p1.GetY();
    double a2 = p2.GetX() - p1.GetX();
    return a1 * a2;
}

std::string CRectangle::GetType() const
{
    return type;
}

void CRectangle::Draw(sf::RenderWindow& window)
{
    int a1 = p2.GetY() - p1.GetY();
    int a2 = p2.GetX() - p1.GetX();
    sf::Vector2f vect1(a1, a2);
    sf::RectangleShape rectangle(vect1);
    
    sf::Vector2f vect2(a1 / 2, a2 / 2);
    rectangle.setPosition(vect2);
    rectangle.setFillColor(sf::Color(175, 180, 240));
    
    window.draw(rectangle);
}
