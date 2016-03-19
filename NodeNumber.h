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

    NodeNumber(long long n,NodeGuiBag *gui, NodeID id):NodeFinal(gui,id),num(n)
    {}
    virtual NodeBase* copy() const override
    {
        return new NodeNumber(*this);
    }

    long long getNumber() const;
    void setNumber(long long value);
//#ifdef DEBUG
//    virtual size_t size() const override
//    {
//        return 1;
//    }
//    virtual std::string nodeName() const override
//    {
//        return "NodeNumber";
//    }
//    virtual void print(std::ostream& o,size_t line) const override
//    {
//        assert(line==0);
//        o<<nodeidentity()<<" with value="<<num;
//    }
//#endif // DEBUG

    virtual std::string notation() const override;
    virtual SizeFactor getMinimumSizeFactor(DepthNum) const override;


protected:

    long long num;
};

#endif // NODENUMBER_H
