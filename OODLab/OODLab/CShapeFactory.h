#pragma once
#include "CCircle.h"
#include "CPoint.h"
#include "CRectangle.h"
#include "CTriangle.h"
#include "CShapeDecorator.h"
#include "CShape.h"
#include "IShape.h"
#include <memory>
#include <string>

class CShapeFactory
{
public:
	std::shared_ptr<CShapeDecorator> CreateShape(const std::string& type, std::istream& input) const;
	static CShapeFactory& GetInstance()
	{
		static CShapeFactory instance;
		return instance;
	}
private:
	CShapeFactory()
	{}
};

