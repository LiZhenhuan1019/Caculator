#ifndef NODEDIVIDE_H
#define NODEDIVIDE_H

#include "NodeHorizontal.h"


class NodeDivide : public NodeHorizontal
{
    friend class Expression;
    friend class ExprFactory;
    friend class OperatorTable;
public:
    //------------special members
        NodeDivide() = default;
        virtual ~NodeDivide() = default;
        NodeDivide(const NodeDivide& other) = default;
    //---------------------------------------------
    using NodeHorizontal::NodeHorizontal;
    virtual NodeBase* copy() const override
    {
        return new NodeDivide(*this);
    }

//#ifdef DEBUG
//    virtual std::string nodeName() const override
//    {
//        return "NodeDivide";
//    }
//#endif // DEBUG

    virtual std::string notation() const override
    {
        return "/";
    }
    static size_t level()
    {
        return ilevel;
    }
protected:
    static size_t ilevel;
};

#endif // NODEDIVIDE_H
