//
// Class header for Value which implements interface INode
//

#ifndef VALUE_H
#define VALUE_H

#include "INode.h"
#include <iostream>

#define VALUE_TYPE 1

class Value : public INode {

public:
    explicit Value(int number);
    [[nodiscard]] int type() const override;

private:
    int num;

};

#endif //VALUE_H
