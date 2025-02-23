//
// Implementation of Value class
//

#include "Value.h"

Value::Value(int number) {
    this->num = number;
}

void Value::visit() const {
    std::cout << this->num << " ";
}


