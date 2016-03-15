#include "NodeBase.h"
#include "NodeGeometry.h"
#include "OutputBase.h"
#include "GraphicsSeparator.h"

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
    return geometry->getCurrentSize();
}

void NodeBase::setCurrentSize(Size newSize)
{
    geometry->setCurrentSize(newSize);
}

SizeFactor NodeBase::getFactorOfCurrentSize() const
{
    return geometry->getFactorOfCurrentSize();
}

void NodeBase::setFactorOfCurrentSize(SizeFactor s)
{
    geometry->setFactorOfCurrentSize(s);
}

void NodeBase::updateSize(SizeFactor /*sizeFactor*/)
{
    geometry->prepareGeometryChange();
}

DefaultGraphicsSeparator *NodeBase::getGraphicsItem() const
{
    return geometry->getGraphicsItem();
}
void NodeBase::setGraphicsItem(DefaultGraphicsSeparator *value)
{
    geometry->setGraphicsItem(value);
}

NodeHelperInfo *NodeBase::getNodeHelper() const
{
    return geometry->getNodeHelper();
}

void NodeBase::setNodeHelper(NodeHelperInfo *value)
{
    setNodeHelper(value);
}


NodeBase::NodeBase(DefaultNodeGeometry *geo):geometry(geo)
{
    geo->setNode(this);
}

NodeBase::~NodeBase()
{
    geometry->cancelReferRelationWithNode();
}


Point NodeBase::getCurrentTopLeft() const
{
    return geometry->getCurrentTopLeft();
}
void NodeBase::setCurrentTopLeft(const Point &value, const Size &parentSize)
{
    geometry->setCurrentTopLeft(value,parentSize);
}

