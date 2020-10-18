
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

vector<unique_ptr<CShapeDecorator>> ReadData(istream& input) 
{
	std::vector<unique_ptr<CShapeDecorator>> shapes;
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
            auto shape = make_unique<CShape>();
            auto rectangle = make_unique<CRectangle>(move(shape), x1, y1, x2, y2);

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
            auto shape = make_unique<CShape>();
            auto triangle = make_unique<CTriangle>(move(shape), x1, y1, x2, y2, x3, y3);

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
            auto shape = make_unique<CShape>();
            auto circle = make_unique<CCircle>(move(shape), x1, y1, radius);
 
            circle->SetPerim();
            circle->SetSquare();
            
            shapes.push_back(move(circle));
        }
    }

	return shapes;
}

void PrintShapes(vector<unique_ptr<CShapeDecorator>>& shapes, sf::RenderWindow& window) 
{
    for(int i = 0; i < shapes.size();++i)
    {
        shapes[i]->Draw(window);
    }
}

void PrintShapesInfo(vector<unique_ptr<CShapeDecorator>>& shapes, ostream& output)
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
	
    vector<unique_ptr<CShapeDecorator>> shapes = ReadData(input);

    PrintShapesInfo(shapes, output);

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
            {
                window.close();
            }
        }
        window.clear();

        PrintShapes(shapes, window);

        window.display();
    }

    return 0;
}
