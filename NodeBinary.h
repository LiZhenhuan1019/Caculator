#ifndef NODEBINARY_H
#define NODEBINARY_H
#include "NodeBase.h"
#include "expression.h"
#include "NodeGeometry.h"

class DisplayHint;
class NodeBinary : public NodeBase
{
    friend class Expression;
    friend class ExprFactory;
    friend class OperatorTable;
public:
    //------special members
    NodeBinary() = default;
    virtual ~NodeBinary() = default;
    NodeBinary(const NodeBinary& other) = default;
    //---------------------------------------------
    NodeBinary(Expression&& el,Expression&& er,DefaultNodeGeometry *geo);
    NodeBinary(NodeBase* pl,NodeBase* pr,DefaultNodeGeometry *geo)
      :NodeBinary(Expression(pl),Expression(pr),geo)
    {}

    Expression const& getLeft() const;
    void setLeft(Expression &&value);

    Expression const& getRight() const;
    void setRight(Expression &&value);
protected:

    void updateLeftChildGraphicsItemParentRelation();
    void updateRightChildGraphicsItemParentRelation();

    Expression left;
    Expression right;
};

#endif // NODEBINARY_H
