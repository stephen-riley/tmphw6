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

void Operator::visit() const {
    std::cout << "[DEBUG] Visiting Operator: " << operation << std::endl;
    if(left) {
        std::cout << "[DEBUG] Operator left: " << std::endl;
        this->left->visit();
    }
    else {
        std::cout << "[DEBUG] Left Child is NULL" << std::endl;
    }

    std::cout << this->operation << " ";

    if(right) {
        std::cout << "[DEBUG] Operator right: " << std::endl;
        this->right->visit();
    }
    else {
        std::cout << "[DEBUG] Right Child is NULL" << std::endl;
    }
}

