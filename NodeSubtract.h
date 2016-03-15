#ifndef NODESUBTRACT_H
#define NODESUBTRACT_H

#include "NodeHorizontal.h"


class NodeSubtract : public NodeHorizontal
{
    friend class Expression;
    friend class ExprFactory;
    friend class OperatorTable;
public:
    //------------special members
        NodeSubtract() = default;
        virtual ~NodeSubtract() = default;
        NodeSubtract(const NodeSubtract& other) = default;
    //---------------------------------------------
    using NodeHorizontal::NodeHorizontal;
    virtual NodeBase* copy() const override
    {
        return new NodeSubtract(*this);
    }
//#ifdef DEBUG
//    virtual std::string nodeName() const override
//    {
//        return "NodeSubtract";
//    }
//#endif // DEBUG

    virtual std::string notation() const override
    {
        return "-";
    }

    static size_t level()
    {
        return ilevel;
    }
protected:
    static size_t ilevel;
};

#endif // NODESUBTRACT_H
