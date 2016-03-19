#ifndef NODENUMBER_H
#define NODENUMBER_H
#include "NodeFinal.h"


class NodeNumber : public NodeFinal
{
    //friend class Expression;
    //friend class ExprFactory;
public:
    NodeNumber() = default;
    virtual ~NodeNumber() = default;
    NodeNumber(NodeNumber const&) = default;

    NodeNumber(long long n,DefaultNodeGeometry *geo):NodeFinal(geo),num(n)
    {}
    virtual NodeBase* copy() const override
    {
        return new NodeNumber(*this);
    }

    long long getNumber() const;
    void setNumber(long long value);

    virtual std::string notation() const override;
    virtual SizeFactor getMinimumSizeFactor(DepthNum) const override;


protected:

    long long num;
};

#endif // NODENUMBER_H
