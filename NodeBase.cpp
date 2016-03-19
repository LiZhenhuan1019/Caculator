#include "NodeBase.h"
#include "NodeGuiItem.h"
#include "OutputBase.h"
#include "DefaultGraphicsSeparator.h"

//#ifdef DEBUG
//size_t Node_base::idcount = 0;
//#endif // DEBUG


Size NodeBase::getCurrentSize() const
{
//    if(sizeFactor!=currentFactor||!isSizeUpdated())
//    {
//        currentFactor = sizeFactor;
//        updateSizeHint();
//    }
    return getGuiItem()->getCurrentSize();
}

void NodeBase::setCurrentSize(Size newSize)
{
    getGuiItem()->setCurrentSize(newSize);
}

SizeFactor NodeBase::getFactorOfCurrentSize() const
{
    return getGuiItem()->getFactorOfCurrentSize();
}

void NodeBase::setFactorOfCurrentSize(SizeFactor s)
{
    getGuiItem()->setFactorOfCurrentSize(s);
}

void NodeBase::updateSize(SizeFactor /*sizeFactor*/)
{
    getGuiItem()->prepareGeometryChange();
}

GraphicsSeparatorT *NodeBase::getGraphicsItem() const
{
    return getGuiItem()->getGraphicsItem();
}
void NodeBase::setGraphicsItem(GraphicsSeparatorT *value)
{
    getGuiItem()->setGraphicsItem(value);
}

NodeHelperInfo *NodeBase::getNodeHelper() const
{
    return getGuiItem()->getNodeHelper();
}

void NodeBase::setNodeHelper(NodeHelperInfo *value)
{
    getGuiItem()->setNodeHelper(value);
}


NodeBase::NodeBase(NodeGuiBag *gui, NodeID i)
    :id(i)
{
    setGuiBag(gui);
}

NodeBase::~NodeBase()
{
    getGuiItem()->cancelReferRelationWithNode();
}


Point NodeBase::getCurrentTopLeft() const
{
    return getGuiItem()->getCurrentTopLeft();
}
void NodeBase::setCurrentTopLeft(const Point &value, const Size &parentSize)
{
    getGuiItem()->setCurrentTopLeft(value,parentSize);
}

