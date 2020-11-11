#pragma once
#include "IShape.h"

class CShapeDecorator;

class IVisitor
{
public:
	virtual void Visit(CShapeDecorator& shape) const = 0;
};
