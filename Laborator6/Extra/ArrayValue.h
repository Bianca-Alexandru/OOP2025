#pragma once
#include "JsonValue.h"
class ArrayValue :public JsonValue
{
	JsonValue* v[16];
	int n;
public:
	ArrayValue();
	~ArrayValue();
	void add(JsonValue* value);
	void print(std::ostream& out)const override;
	operator unsigned()const;
};

