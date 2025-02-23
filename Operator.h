//
// Class header for Operator which implements interface INode
//

#ifndef OPERATOR_H
#define OPERATOR_H

#include "INode.h"
#include <iostream>
#include <string>

#define OPERATOR_TYPE 2

class Operator : public INode {
public:
    INode* left;
    INode* right;
    std::string operation;

    Operator(const std::string& operation, INode* left, INode* right);

    [[nodiscard]] int type() const override;
    ~Operator() override;
};


#endif //OPERATOR_H
