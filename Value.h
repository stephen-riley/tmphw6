//
// Class header for Value which implements interface INode
//

#ifndef VALUE_H
#define VALUE_H

#include "INode.h"
#include <iostream>

class Value : public INode {

public:
    explicit Value(int number);
    void visit() const;

private:
    int num;

};

#endif //VALUE_H
