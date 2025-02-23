//
// Interface header for INode
//

#ifndef INODE_H
#define INODE_H

class INode {
public:
    [[nodiscard]] virtual int type() const = 0;
    virtual ~INode() = default;
};


#endif //INODE_H
