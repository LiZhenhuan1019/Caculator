#ifndef NODEADD_H
#define NODEADD_H

#include "NodeHorizontal.h"

class NodeAdd : public NodeHorizontal
{
    friend class Expression;
    friend class ExprFactory;
    friend class OperatorTable;
public:
    //------------special members
    NodeAdd() = default;
    virtual ~NodeAdd() = default;
    NodeAdd(const NodeAdd& other) = default;
    //---------------------------------------------
    using NodeHorizontal::NodeHorizontal;
    virtual NodeBase* copy() const override
    {
        return new NodeAdd(*this);
    }
//#ifdef DEBUG
//    virtual std::string nodeName() const override
//    {
//        return "NodeAdd";
//    }
//#endif // DEBUG


    virtual std::string notation() const override
    {
        return "+";
    }
    static size_t level()
    {
        return ilevel;
    }
protected:
    static size_t ilevel;
};

#endif // NODEADD_H
