#ifndef NODEUNARY_H
#define NODEUNARY_H

#include "NodeBase.h"
#include "expression.h"
#include "NodeGeometry.h"

class NodeUnary : public NodeBase
{
    friend class Expression;
    friend class ExprFactory;
protected:
    //------special members
    NodeUnary() = default;
    virtual ~NodeUnary() = default;
    NodeUnary(const NodeUnary& other) = default;
    //---------------------------------------------
    explicit NodeUnary(Expression&& e):arg(std::move(e))
    {}
    explicit NodeUnary(NodeBase* p):arg(p)
    {}
    Expression arg;
};

#endif // NODEUNARY_H
