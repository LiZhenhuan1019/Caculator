#ifndef NODEGEOMETRY_H
#define NODEGEOMETRY_H
#include "GraphicsElements.h"
#include "GraphicsSeparatorDeclarations.h"
#include "NodeID.h"

class NodeHelperInfo;
class OutputBase;
template <typename NodeBaseType,typename GraphicsType,typename NodeHelperType = NodeHelperInfo>
class NodeGuiItem
{
public:
    using NodeBaseT = NodeBaseType;
    using GraphicsT = GraphicsType;

    NodeGuiItem() = default;
    NodeGuiItem(NodeHelperInfo*p,GraphicsT *g)
        :graphicsItem(g),nodeHelper(p)
    {
        getGraphicsItem()->setNodeGeomerty(this);
    }

//    Point getCurrentTopLeftPoint() const;//for no one

    //for node
    GraphicsType *getGraphicsItem() const
    {
        return graphicsItem;
    }
    void setGraphicsItem(GraphicsType *value)
    {
        graphicsItem = value;
    }

    NodeHelperInfo *getNodeHelper() const
    {
        return nodeHelper;
    }
    void setNodeHelper(NodeHelperInfo *value)
    {
        nodeHelper = value;
    }

    Point getCurrentTopLeft() const
    {
        return currentTopLeft;
    }
    void setCurrentTopLeft(const Point &value, const Size &parentSize)
    {
        currentTopLeft = value;
        getGraphicsItem()->setPos(currentTopLeft,parentSize);
    }

    Size getCurrentSize() const
    {
        return currentSize;
    }
    void setCurrentSize(const Size &value)
    {
        currentSize = value;
    }

    SizeFactor getFactorOfCurrentSize() const
    {
        return factorOfCurrentSize;
    }
    void setFactorOfCurrentSize(const SizeFactor &value)
    {
        factorOfCurrentSize = value;
    }

    //for node,delegate to NodeSeparator
    void prepareGeometryChange()
    {
        getGraphicsItem()->prepareGeometryChange();
    }

    void cancelReferRelationWithNode()
    {
        getGraphicsItem()->cancelReferRelationWithNode();
    }

    //for GraphicsItem(template parameter of GraphicsSeparator
    void display(OutputBase &o,Point topLeft)
    {
        node->display(o,topLeft);
    }

    void setNode(NodeBaseType *value)
    {
        node = value;
    }//for NodeBaseType

    NodeID id;
protected:
    GraphicsType *graphicsItem = nullptr;
    NodeHelperInfo* nodeHelper = nullptr;
    NodeBaseType* node = nullptr;

    Point currentTopLeft;
    Size currentSize;
    SizeFactor factorOfCurrentSize = -1;
};

#endif // NODEGEOMETRY_H
