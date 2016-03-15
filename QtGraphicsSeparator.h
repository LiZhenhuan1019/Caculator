#ifndef QTNODEGRAPHICS_H
#define QTNODEGRAPHICS_H
#include "GraphicsSeparator.h"
#include "GraphicsSeparatorDeclarations.h"

class QtGraphicsSeparator : public DefaultGraphicsSeparator
{
public:
    QtGraphicsSeparator() = default;
    QtGraphicsSeparator(GraphicsItemT *pItem, DefaultNodeGeometry *pNodegeo);

    virtual void setParent(DefaultGraphicsSeparator *pParent) override;
    virtual void prepareGeometryChange() override;  //for NodeGeometry
    virtual void setPos(Point p,Size const&parentSize) override;//for NodeGeometry
    virtual void cancelReferRelationWithNode() override;//for NodeGeometry

    virtual void setItem(GraphicsItemT*pItem) override;
    virtual GraphicsItemT* getItem() const override;


private:
    GraphicsItemT *item = nullptr;
};

#endif // QTNODEGRAPHICS_H
