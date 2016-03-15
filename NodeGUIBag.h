#ifndef NODEGUIBAG_H
#define NODEGUIBAG_H

#include <unordered_map>
#include "NodeGuiDeclaration.h"
#include "NodeGuiItem.h"
class NodeGuiBag
{
public:
    void addGuiItem(DefaultNodeGeometry*item)
    {
        items[item->id]=item;
    }
    DefaultNodeGeometry*getGuiItem(NodeID id)
    {
        return items[id];
    }

private:
    std::unordered_map<NodeID,DefaultNodeGeometry*> items;
};

#endif // NODEGUIBAG_H
