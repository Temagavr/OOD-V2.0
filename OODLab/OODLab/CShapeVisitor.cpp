#include "CShapeVisitor.h"

void CShapeVisitor::Visit(CShapeDecorator& shape) const
{
	output << shape.GetType() << ": P= " << shape.GetPerim() << ", S= " << shape.GetSquare() << std::endl;
}
