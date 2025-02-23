//
// Class header for Operator which implements interface INode
//

#ifndef OPERATOR_H
#define OPERATOR_H

#include "INode.h"
#include <iostream>
#include <string>


class Operator : public INode {
public:
    INode* left;
    INode* right;
    std::string operation;

    Operator(const std::string& operation, INode* left, INode* right);
    void visit() const;
    ~Operator();
};


#endif //OPERATOR_H
