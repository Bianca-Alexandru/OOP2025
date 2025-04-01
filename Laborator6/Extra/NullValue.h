#pragma once
#include "JsonValue.h"
class NullValue : public JsonValue
{
	
public:
	NullValue();
	~NullValue();
	void print(std::ostream& out)const;
};

