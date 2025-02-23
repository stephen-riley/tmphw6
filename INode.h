//
// Interface header for INode
//

#ifndef INODE_H
#define INODE_H

class INode {
public:
    virtual void visit() const = 0;
    virtual ~INode() = default;
};


#endif //INODE_H
