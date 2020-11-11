
#include <iostream>
#include <fstream>
#include <SFML/Graphics.hpp>
#include "CShapeDecorator.h"
#include "CCircle.h"
#include "CTriangle.h"
#include "CRectangle.h"
#include "CShape.h"
#include "CShapeFactory.h"
#include "InputData.h"
#include "CShapeVisitor.h"
#include <vector>

using namespace std;

const string RECTANGLE = "RECTANGLE:";
const string TRIANGLE = "TRIANGLE:";
const string CIRCLE = "CIRCLE:";

vector<shared_ptr<CShapeDecorator>> ReadData(istream& input) 
{
	vector<shared_ptr<CShapeDecorator>> shapes;
    auto& factory = CShapeFactory::GetInstance();// make_unique<CShapeFactory>();
    auto inputShape = make_shared<InputData>(move(make_unique<CShapeFactory>(factory)));
    string temp;
    while (!input.eof())
    {
        input >> temp;
        if (temp == RECTANGLE || temp == TRIANGLE || temp == CIRCLE)
        {
            shared_ptr<CShapeDecorator> shape = inputShape->GetCreatedShape(temp, input);
            shapes.push_back(shape);
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
    CShapeVisitor visitor(output);
    for (int i = 0; i < shapes.size();++i)
    {
        //shapes[i]->PrintInfo(output);
        shapes[i]->Accept(visitor);
    }
}

int main()
{
    ifstream input;
    ofstream output;
    input.open("input1.txt");
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
