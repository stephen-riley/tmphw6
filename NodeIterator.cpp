//
// Implementation of Node Iterator class
//

#include "NodeIterator.h"
#include "Operator.h"
#include <stack>

// Constructor
NodeIterator::NodeIterator(INode* root) {
    Root = root;
}

// Postfix traversal method, returns Generator of INode*
Generator<INode *> NodeIterator::PostfixNodeStream() {
    // Handle empty tree
    if(!Root) {
        std::cout << "[DEBUG] Root is NULL, exiting traversal" << std::endl;
        co_return;
    }

    // Create stack of INode* for traversal
    std::stack<INode*> nodeStack;

    // Create stack for storing nodes in postfix order
    std::stack<INode*> outputStack;

    std::cout << "[DEBUG] Starting postfix traversal" << std::endl;
    nodeStack.push(Root);

    while(!nodeStack.empty()) {
        INode* current = nodeStack.top();
        nodeStack.pop();
        outputStack.push(current);

        std::cout << "[DEBUG] Processing Node: " << typeid(*current).name() << std::endl;
        // If current node is an operator, push children onto the stack
        if(Operator* opNode = dynamic_cast<Operator*>(current)) {
            std::cout << "[DEBUG] Node is an Operator" << std::endl;
            if(opNode->left) {
                std::cout << "[DEBUG] Pushing Left Child" << std::endl;
                nodeStack.push(opNode->left);
            }
            if(opNode->right) {
                std::cout << "[DEBUG] Pushing Right Child" << std::endl;
                nodeStack.push(opNode->right);
            }
        }
    }

    std::cout << "[DEBUG] Yielding nodes in postfix order" << std::endl;

    // Generator nodes in postfix order
    while (!outputStack.empty()) {
        INode* node = outputStack.top();
        outputStack.pop();

        if(!node) {
            std::cout << "[DEBUG] Node is NULL" << std::endl;
            continue;
        }

        std::cout << "[DEBUG] Processing Node: " << typeid(*node).name() << std::endl;
        co_yield node;
    }

    std::cout << "[DEBUG] Exiting postfix traversal" << std::endl;

}
