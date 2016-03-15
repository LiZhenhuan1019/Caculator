#ifndef NODEFINAL_H
#define NODEFINAL_H
#include "NodeGeometry.h"
#include "NodeBase.h"


class NodeFinal : public NodeBase
{
    friend class Expression;
    friend class ExprFactory;
public:
    //------special members
    NodeFinal() = default;
    NodeFinal(DefaultNodeGeometry *geo):NodeBase(geo)
    {}
    virtual ~NodeFinal() = default;
    NodeFinal(const NodeFinal& other) = default;


    virtual void display(OutputBase &o,Point topLeft) const override;
protected:
//    virtual bool isSizeUpdated() const override;
    virtual void updateSize(SizeFactor sizeFactor) override;
//    mutable bool mIsSizeUpdated = false;

};

#endif // NODEFINAL_H
