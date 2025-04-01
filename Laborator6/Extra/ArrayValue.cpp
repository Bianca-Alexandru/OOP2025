#include "ArrayValue.h"
#include <iostream>

ArrayValue::ArrayValue()
{
	this->n = 0;
}

ArrayValue::~ArrayValue()
{
	for (int i = 0;i < n;i++)
		delete v[i];
}
void ArrayValue::add(JsonValue* value) {
    if (n < 16) {
        v[n++] = value;  
    }
}

void ArrayValue::print(std::ostream& out) const {
    out << "[";

    for (int i = 0; i < n; ++i) {
        if (i > 0) {
            out << ", ";
        }
        v[i]->print(out);  
    }

    out << "]";
}
ArrayValue::operator unsigned() const {
    return n;  
}