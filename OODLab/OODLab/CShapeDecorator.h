#pragma once

#include "IShape.h"
#include "CPoint.h"
#include <string>

class CShapeDecorator : public IShape
{
public:

	CShapeDecorator(std::shared_ptr<IShape>&& shape) :
		shape(move(shape))
	{};

	void SetPerim(double per) override {};
	void SetSquare(double square) override {};
	
	double GetPerim() const override
	{
		return shape->GetPerim();
	}

	double GetSquare() const override
	{
		return shape->GetSquare();
	}

	void SetPerim()
	{
		double per = CalcPerim();
		shape->SetPerim(per);
	}

	void SetSquare()
	{
		double square = CalcSquare();
		shape->SetSquare(square);
	}

	void PrintInfo(std::ostream& output)
	{
		output <<GetType() << ": P= " << GetPerim() << ", S= " << GetSquare() << std::endl;
	}

	virtual double CalcPerim() = 0;
	virtual double CalcSquare() = 0;
	virtual std::string GetType() const = 0;
	
	virtual void Draw(sf::RenderWindow& window) = 0;
	virtual bool CheckClick(int x, int y) = 0;
	virtual CPoint GetCenter() const = 0;
	virtual void MoveShape(int x, int y, sf::RenderWindow& window) = 0;
	virtual void DeleteBorder() = 0;


private:
	std::shared_ptr<IShape> shape;
};