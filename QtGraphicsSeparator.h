#ifndef QTNODEGRAPHICS_H
#define QTNODEGRAPHICS_H
#include "DefaultGraphicsSeparator.h"
#include "GraphicsSeparatorDeclarations.h"

class QtGraphicsSeparator : public GraphicsSeparatorT
{
public:
    QtGraphicsSeparator() = default;
    QtGraphicsSeparator(GraphicsItemT *pItem, DefaultNodeGeometry *pNodegeo);

    virtual void setParent(DefaultGraphicsSeparator *pParent) override;
    virtual void prepareGeometryChange() override;  //for NodeGuiItem
    virtual void setPos(Point p,Size const&parentSize) override;//for NodeGuiItem
    virtual void cancelReferRelationWithNode() override;//for NodeGuiItem

    virtual void setItem(GraphicsItemT*pItem) override;
    virtual GraphicsItemT* getItem() const override;


private:
    GraphicsItemT *item = nullptr;
};

#endif // QTNODEGRAPHICS_H
