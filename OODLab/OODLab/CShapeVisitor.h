#pragma once
#include "IVisitor.h"
#include "CShapeDecorator.h"
#include <istream>

class CShapeVisitor : public IVisitor
{
public:
	CShapeVisitor(std::ostream& out)
		:output(out)
	{};

	void Visit(CShapeDecorator& shape) const override;
private:
	std::ostream& output;
};

