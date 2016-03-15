#ifndef NODEBAG_H
#define NODEBAG_H
#include <unordered_map>
#include "expression.h"
class NodeBag
{
public:
    void setTopExpression(Expression e)
    {
        nodes.clear();
        addNode(e.get());
        topExpression=std::move(e);
    }
    NodeBase* getTopExpression()const
    {
        return topExpression.get();
    }
    void addNode(NodeBase*n)
    {
        nodes[n->id]=n;
    }
    NodeBase*getNode(NodeID id)
    {
        return nodes[id];
    }

private:
    Expression topExpression;
    std::unordered_map<NodeID,NodeBase*> nodes;
};


#endif // NODEBAG_H
