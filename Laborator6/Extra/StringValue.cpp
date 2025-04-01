#include "StringValue.h"


StringValue::StringValue(const char* c)
{
	strcpy_s(s,sizeof(s), c);
}

StringValue::~StringValue()
{
	delete s;
}

void StringValue::print(std::ostream& out) const
{
	out << "\""<<s<<"\"";
}


