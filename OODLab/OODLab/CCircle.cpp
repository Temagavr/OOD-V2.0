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

bool CCircle::CheckClick(int x, int y)
{
    if (circle.getGlobalBounds().contains(x, y))
        return true;
    else
        return false;
}

void CCircle::MoveShape(int x, int y, sf::RenderWindow& window)
{
    circle.setPosition(x, y);
    circle.setOutlineThickness(2);
    circle.setOutlineColor(sf::Color(255, 255, 255, 255));
    center.SetX(x);
    center.SetY(y);
}

void CCircle::Draw(sf::RenderWindow& window)
{
    circle.setFillColor(sf::Color(0x0, 0xFF, 0x0));
    window.draw(circle);
}

void CCircle::DeleteBorder()
{
    circle.setOutlineThickness(0);
}
