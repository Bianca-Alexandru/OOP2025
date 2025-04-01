#pragma once
#include "JsonValue.h"

class StringValue : public JsonValue
{
	char s[256];
public:
	StringValue(const char* c);
	~StringValue();
	void print(std::ostream& out)const;
};

