#ifndef NODEMULTI_H
#define NODEMULTI_H

#include "NodeHorizontal.h"

class NodeMulti : public NodeHorizontal
{
    friend class Expression;
    friend class ExprFactory;
    friend class OperatorTable;
public:
    //------special members
    NodeMulti() = default;
    virtual ~NodeMulti() = default;
    NodeMulti(const NodeMulti& other) = default;
    //---------------------------------------------
    using NodeHorizontal::NodeHorizontal;
    virtual NodeBase* copy() const override
    {
        return new NodeMulti(*this);
    }
    virtual std::string notation() const override
    {
        return "*";
    }
    static size_t level()
    {
        return ilevel;
    }
protected:
    static size_t ilevel;
};

#endif // NODEMULTI_H
