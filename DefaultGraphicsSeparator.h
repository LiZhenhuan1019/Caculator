#ifndef GRAPHICSSEPARATOR_H
#define GRAPHICSSEPARATOR_H
#include "GraphicsElements.h"
#include "NodeGuiDeclaration.h"
class NodeBase;
template <typename GraphicsItem>
class DefaultGraphicsSeparator
{
public:
    using GraphicsItemT = GraphicsItem;

    DefaultGraphicsSeparator() = default;
    DefaultGraphicsSeparator(DefaultNodeGeometry *p):nodeGeometry(p)
    {}
    virtual ~DefaultGraphicsSeparator() = default;

    //for Node_base
    virtual void setParent(DefaultGraphicsSeparator<GraphicsItem> *pParent) = 0;
    virtual void prepareGeometryChange() = 0;//for NodeGuiItem
    virtual void setPos(Point p,Size const&parentSize) = 0;//for NodeGuiItem
    virtual void cancelReferRelationWithNode() = 0;//for NodeGuiItem

    virtual void setItem(GraphicsItem*pItem) = 0;
    //for GraphicsItem
    virtual GraphicsItem* getItem() const = 0;
    DefaultNodeGeometry *getNodeGeometry() const
    {
        return nodeGeometry;
    }
    void setNodeGeomerty(DefaultNodeGeometry *value)//for NodeGuiItem
    {
        nodeGeometry = value;
    }

private:
    DefaultNodeGeometry *nodeGeometry = nullptr;
};

#endif // GRAPHICSSEPARATOR_H
