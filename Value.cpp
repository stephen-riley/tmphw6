//
// Implementation of Value class
//

#include "Value.h"

Value::Value(int number) {
    this->num = number;
}

int Value::type() const { return VALUE_TYPE; }

