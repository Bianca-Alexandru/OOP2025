#pragma once
#include "JsonValue.h"
class BoolValue : public JsonValue
{
	bool x;
public:
	BoolValue(bool x);
	~BoolValue();
	void print(std::ostream& out)const;
};

