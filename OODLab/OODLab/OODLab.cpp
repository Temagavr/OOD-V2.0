
#include <iostream>
#include <fstream>
#include <SFML/Graphics.hpp>
#include "CShapeDecorator.h"
#include "CCircle.h"
#include "CTriangle.h"
#include "CRectangle.h"
#include "CShape.h"
#include <vector>

using namespace std;

const string RECTANGLE = "RECTANGLE:";
const string TRIANGLE = "TRIANGLE:";
const string CIRCLE = "CIRCLE:";
const string P1 = "P1=";
const string P2 = "P2=";
const string P3 = "P3=";
const string R = "R=";
const string C = "C=";

vector<shared_ptr<CShapeDecorator>> ReadData(istream& input) 
{
	vector<shared_ptr<CShapeDecorator>> shapes;
    while (!input.eof())
    {
        string temp;
        input >> temp;
        if (temp == RECTANGLE)
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
            auto shape = make_shared<CShape>();
            auto rectangle = make_shared<CRectangle>(move(shape), x1, y1, x2, y2);

            rectangle->SetPerim();
            rectangle->SetSquare();

            shapes.push_back(move(rectangle));
        }

        if (temp == TRIANGLE)
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
            auto shape = make_shared<CShape>();
            auto triangle = make_shared<CTriangle>(move(shape), x1, y1, x2, y2, x3, y3);

            triangle->SetPerim();
            triangle->SetSquare();

            shapes.push_back(move(triangle));

        }

        if (temp == CIRCLE)
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
            auto shape = make_shared<CShape>();
            auto circle = make_shared<CCircle>(move(shape), x1, y1, radius);
 
            circle->SetPerim();
            circle->SetSquare();

            shapes.push_back(move(circle));
        }
    }

	return shapes;
}

void DrawShapes(vector<shared_ptr<CShapeDecorator>>& shapes, sf::RenderWindow& window) 
{
    for(int i = 0; i < shapes.size();++i)
    {
        shapes[i]->Draw(window);
    }
}

bool CheckClickShapes(vector<shared_ptr<CShapeDecorator>>& shapes, int x, int y)
{
    for (int i = 0; i < shapes.size();++i)
    {
        if (shapes[i]->CheckClick(x, y))
            return true;
    }
    return false;
}

shared_ptr<CShapeDecorator> FindShape(vector<shared_ptr<CShapeDecorator>>& shapes, int x, int y)
{
    int p = 0;
    for (int i = 0; i < shapes.size();++i)
    {
        if (shapes[i]->CheckClick(x, y))
            p = i;
    }
        shared_ptr<CShapeDecorator> temp = shapes[p];
        return temp;
    
}

void PrintShapesInfo(vector<shared_ptr<CShapeDecorator>>& shapes, ostream& output)
{
    for (int i = 0; i < shapes.size();++i)
    {
        shapes[i]->PrintInfo(output);
    }
}

int main()
{
    ifstream input;
    ofstream output;
    input.open("input.txt");
    output.open("output.txt");

	sf::RenderWindow window(sf::VideoMode({ 600, 600 }), "title");
	window.clear();
	
    vector<shared_ptr<CShapeDecorator>> shapes = ReadData(input);

    PrintShapesInfo(shapes, output);

    int dX = 0, dY = 0;
    bool isMove = false;

    shared_ptr<CShapeDecorator> temp;
    while (window.isOpen())
    {
        
        sf::Vector2i pixelPos = sf::Mouse::getPosition(window);
        sf::Vector2f pos = window.mapPixelToCoords(pixelPos);

        sf::Event event;
        
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
            
            if (event.type == sf::Event::MouseButtonPressed)
            {
                if (event.key.code == sf::Mouse::Left)
                {
                    if (CheckClickShapes(shapes, pos.x, pos.y))
                    {
                        isMove = true;
                        temp = FindShape(shapes, pos.x, pos.y);
                        dX = pos.x - temp->GetCenter().GetX();
                        dY = pos.y - temp->GetCenter().GetY();
                    }
                }
            }

            if (event.type == sf::Event::MouseButtonReleased)
            {
                if (event.key.code == sf::Mouse::Left)
                {
                    isMove = false;
                    temp->DeleteBorder();
                }
            }

        }

        if (isMove)
        {
            temp->MoveShape(pos.x - dX, pos.y - dY, window);
        }

        window.clear();

        DrawShapes(shapes, window);

        window.display();
    }

    return 0;
}
