#include "QtGraphicsSeparator.h"
#include "QtExpressionItem.h"
#include "QtGraphicsConvert.h"
#include "NodeBase.h"
#include "NodeGuiItem.h"


QtGraphicsSeparator::QtGraphicsSeparator(GraphicsSeparatorT::GraphicsItemT *pItem, DefaultNodeGeometry *pNodegeo)
    :GraphicsSeparatorT(pNodegeo),item(pItem)
{
    item->setseparator(this);
}

void QtGraphicsSeparator::setParent(GraphicsSeparatorT *pParent)
{
    item->setParentItem(pParent->getItem());
}

void QtGraphicsSeparator::prepareGeometryChange()
{
    item->prepareGeometryChange();
}


void QtGraphicsSeparator::setPos(Point p, const Size &parentSize)
{
    Size halfSizeOfParent = parentSize/2;
    Point centreOfParent(halfSizeOfParent.width(),halfSizeOfParent.height());
    Size halfSizeOfMe = getNodeGeometry()->getCurrentSize()/2;
    Point centreOfMe(halfSizeOfMe.width(),halfSizeOfMe.height());
    item->setPos(toQPointF(p+centreOfMe-centreOfParent));
}

void QtGraphicsSeparator::cancelReferRelationWithNode()
{
    setNodeGeomerty(nullptr);
    delete item;
    delete this;
}

void QtGraphicsSeparator::setItem(GraphicsSeparatorT::GraphicsItemT *pItem)
{
    delete item;
    item = pItem;
    item->setseparator(this);
}

QtGraphicsSeparator::GraphicsItemT *QtGraphicsSeparator::getItem() const
{
    return item;
}
