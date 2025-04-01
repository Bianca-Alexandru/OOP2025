#pragma once
#include "JsonValue.h"
class NumberValue: public JsonValue
{
	int x;
public:
	NumberValue(int y);
	~NumberValue();
	void print(std::ostream& out)const;
};

