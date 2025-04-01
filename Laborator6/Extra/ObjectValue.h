#pragma once
#include "JsonValue.h"
#include <iostream>

class ObjectValue : public JsonValue {
    struct Pair {
        char key[256];  
        JsonValue* value;
    };

    Pair pairs[16];  
    int n;          

public:
    ObjectValue();
    ~ObjectValue();
    void add(const char* key, JsonValue* value);
    void print(std::ostream& out) const override;
    operator unsigned() const;
};
