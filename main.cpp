
#include "Value.h"
#include "Operator.h"
#include "NodeIterator.h"
#include <iostream>


int main() {

    std::cout << "[DEBUG] Constructing expression tree" << std::endl;
    // Constructing Expression Tree
    INode* root = new Operator(
        std::string("*"),
        new Operator(
            std::string("+"),
            new Value(6),
            new Value(7)),
        new Value(6)
        );
    std::cout << "[DEBUG] Created expression tree" << std::endl;


    // Create iterator for traversal with root as input
    NodeIterator iterator(root);

    std::cout << "[DEBUG] Starting Postfix Order Traversal" << std::endl;
    // Iterate through nodes in postfix order
    for(INode* node : iterator.PostfixNodeStream()) {
        node->visit();
    }

    delete root;
    root = nullptr;

    std::cout << "[DEBUG] Program Finished Successfully" << std::endl;

    return 0;
}

// END