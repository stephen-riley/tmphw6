//
// Implememtatiom of Operator class
//

#include "Operator.h"

Operator::Operator(const std::string& operation, INode* left, INode* right) {
    this->operation = operation;
    this->left = left;
    this->right = right;
}

Operator::~Operator() {

    std::cout << "[DEBUG] Deleting Operator: " << operation << std::endl;
    if(left) {
        delete left;
        left = nullptr;
    }
    if(right) {
        delete right;
        right = nullptr;
    }
}

int Operator::type() const { return OPERATOR_TYPE; }