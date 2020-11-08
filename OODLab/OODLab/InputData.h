#pragma once
#include "CCircle.h"
#include "CPoint.h"
#include "CRectangle.h"
#include "CTriangle.h"
#include "CShapeDecorator.h"
#include "CShape.h"
#include "IShape.h"
#include "CShapeFactory.h"
#include <memory>
#include <string>
#include <vector>

class InputData
{
public:
	InputData(std::unique_ptr<CShapeFactory>&& factory)
		:m_factory(move(factory))
	{}

	std::shared_ptr<CShapeDecorator> GetCreatedShape(const std::string& type, std::istream& input)
	{
		auto shape = m_factory->CreateShape(type, input);

		return shape;
	}

private:
	std::unique_ptr<CShapeFactory> m_factory;
};

