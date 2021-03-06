#include "NodeBinary.h"
#include "DefaultGraphicsSeparator.h"




NodeBinary::NodeBinary(Expression &&el, Expression &&er, NodeGuiBag *gui, NodeID id)
    :NodeBase(gui,id),left(std::move(el)),right(std::move(er))
{
    updateLeftChildGraphicsItemParentRelation();
    updateRightChildGraphicsItemParentRelation();
}


Expression const& NodeBinary::getLeft() const
{
    return left;
}
void NodeBinary::setLeft(Expression &&value)
{
    left = std::move(value);
    updateLeftChildGraphicsItemParentRelation();
}

Expression const& NodeBinary::getRight() const
{
    return right;
}
void NodeBinary::setRight(Expression &&value)
{
    right = std::move(value);
    updateRightChildGraphicsItemParentRelation();
}


void NodeBinary::updateLeftChildGraphicsItemParentRelation()
{
    left->getGraphicsItem()->setParent(getGraphicsItem());
}
void NodeBinary::updateRightChildGraphicsItemParentRelation()
{
    right->getGraphicsItem()->setParent(getGraphicsItem());
}
