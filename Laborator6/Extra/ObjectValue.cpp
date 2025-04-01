#include "ObjectValue.h"
#include <cstring> 

ObjectValue::ObjectValue() : n(0) {}

ObjectValue::~ObjectValue() {
    for (int i = 0; i < n; ++i) {
        delete pairs[i].value;
    }
}

void ObjectValue::add(const char* key, JsonValue* value) {
    if (n < 16) {
        strcpy_s(pairs[n].key, key);  
        pairs[n].value = value;        
        ++n;                          
    }
}

void ObjectValue::print(std::ostream& out) const {
    out << "{";
    for (int i = 0; i < n; ++i) {
        if (i > 0) out << ", ";  

        out << "\"" << pairs[i].key << "\": ";
        pairs[i].value->print(out);  
    }
    out << "}";
}

ObjectValue::operator unsigned() const {
    return n;
}
