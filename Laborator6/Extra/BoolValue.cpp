#include "BoolValue.h"

BoolValue::BoolValue(bool x)
{
	this->x = x;
}

BoolValue::~BoolValue()
{
}

void BoolValue::print(std::ostream& out) const
{
	if (x)
		out << "true";
	else out << "false";
}
