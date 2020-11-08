#include "CShapeFactory.h"
using namespace std;

const string RECTANGLE = "RECTANGLE:";
const string TRIANGLE = "TRIANGLE:";
const string CIRCLE = "CIRCLE:";
const string P1 = "P1=";
const string P2 = "P2=";
const string P3 = "P3=";
const string R = "R=";
const string C = "C=";

std::shared_ptr<CShapeDecorator> CShapeFactory::CreateShape(const std::string& type, std::istream& input) const
{
    shared_ptr<CShapeDecorator> shape;
    string temp;
    if (type == RECTANGLE)
    {
        int x1, x2, y1, y2;
        input >> temp;
        if (temp == P1)
        {
            input >> temp;
            temp.erase(temp.size() - 1);
            x1 = atoi(temp.c_str());
            input >> temp;
            temp.erase(temp.size() - 1);
            y1 = atoi(temp.c_str());
        }
        input >> temp;
        if (temp == P2)
        {
            input >> temp;
            temp.erase(temp.size() - 1);
            x2 = atoi(temp.c_str());
            input >> temp;
            temp.erase(temp.size() - 1);
            y2 = atoi(temp.c_str());
        }
        auto tempShape = make_shared<CShape>();
        shape = make_shared<CRectangle>(move(tempShape), x1, y1, x2, y2);

    }
    else if (type == TRIANGLE)
    {
        int x1, x2, x3, y1, y2, y3;
        input >> temp;
        if (temp == P1)
        {
            input >> temp;
            temp.erase(temp.size() - 1);
            x1 = atoi(temp.c_str());
            input >> temp;
            temp.erase(temp.size() - 1);
            y1 = atoi(temp.c_str());
        }
        input >> temp;
        if (temp == P2)
        {
            input >> temp;
            temp.erase(temp.size() - 1);
            x2 = atoi(temp.c_str());
            input >> temp;
            temp.erase(temp.size() - 1);
            y2 = atoi(temp.c_str());
        }
        input >> temp;
        if (temp == P3)
        {
            input >> temp;
            temp.erase(temp.size() - 1);
            x3 = atoi(temp.c_str());
            input >> temp;
            temp.erase(temp.size() - 1);
            y3 = atoi(temp.c_str());
        }
        auto tempShape = make_shared<CShape>();
        shape = make_shared<CTriangle>(move(tempShape), x1, y1, x2, y2, x3, y3);

    }
    else if (type == "CIRCLE:")
    {
        int x1, y1, radius;
        input >> temp;
        if (temp == C)
        {
            input >> temp;
            temp.erase(temp.size() - 1);
            x1 = atoi(temp.c_str());
            input >> temp;
            temp.erase(temp.size() - 1);
            y1 = atoi(temp.c_str());
        }
        input >> temp;
        if (temp == R)
        {
            input >> temp;
            temp.erase(temp.size() - 1);
            radius = atoi(temp.c_str());
        }
        auto tempShape = make_shared<CShape>();
        shape = make_shared<CCircle>(move(tempShape), x1, y1, radius);

    }
    else
    {
        cout << type;
    }

    shape->SetPerim();
    shape->SetSquare();
    
    return shape;
}
