#include "NumberValue.h"


NumberValue::NumberValue(int y)
{
	x = y;
}

NumberValue::~NumberValue()
{
}

void NumberValue::print(std::ostream& out) const
{
	out << x;
}
