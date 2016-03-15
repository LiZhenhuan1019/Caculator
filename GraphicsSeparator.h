#ifndef GRAPHICSSEPARATOR_H
#define GRAPHICSSEPARATOR_H
#include "GraphicsElements.h"
#include "NodeGeometryDeclaration.h"
class NodeBase;
template <typename GraphicsItem>
class GraphicsSeparator
{
public:
    using GraphicsItemT = GraphicsItem;

    GraphicsSeparator() = default;
    GraphicsSeparator(DefaultNodeGeometry *p):nodeGeometry(p)
    {}
    virtual ~GraphicsSeparator() = default;

    //for Node_base
    virtual void setParent(GraphicsSeparator<GraphicsItem> *pParent) = 0;
    virtual void prepareGeometryChange() = 0;//for NodeGeometry
    virtual void setPos(Point p,Size const&parentSize) = 0;//for NodeGeometry
    virtual void cancelReferRelationWithNode() = 0;//for NodeGeometry

    virtual void setItem(GraphicsItem*pItem) = 0;
    //for GraphicsItem
    virtual GraphicsItem* getItem() const = 0;
    DefaultNodeGeometry *getNodeGeometry() const
    {
        return nodeGeometry;
    }
    void setNodeGeomerty(DefaultNodeGeometry *value)//for NodeGeometry
    {
        nodeGeometry = value;
    }

private:
    DefaultNodeGeometry *nodeGeometry = nullptr;
};

#endif // GRAPHICSSEPARATOR_H
