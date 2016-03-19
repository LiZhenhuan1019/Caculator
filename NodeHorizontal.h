#ifndef NODEHORIZONTAL_H
#define NODEHORIZONTAL_H
#include "NodeBinary.h"
//对于NodeHorizontal，不保证其两子节点的factorOfCurrentSize总是一致的，（很难保证）
//所以在其updateSize函数中，先确保其一致。
//notation的size factor是节点的size factor
class DisplayHint;
class NodeHorizontal : public NodeBinary
{
    friend class Expression;
    friend class ExprFactory;
    friend class OperatorTable;
public:
    //------special members
    NodeHorizontal() = default;
    virtual ~NodeHorizontal() = default;
    NodeHorizontal(const NodeHorizontal& other) = default;
    //---------------------------------------------
    NodeHorizontal(Expression&& el,Expression&& er,DefaultNodeGeometry *geo)
        :NodeBinary(std::move(el),std::move(er),geo)
    {}

    NodeHorizontal(NodeBase* pl,NodeBase* pr,DefaultNodeGeometry *geo)
      :NodeHorizontal(Expression(pl),Expression(pr),geo)
    {}
    virtual void display(OutputBase &o,Point topLeft) const override;
    virtual void updateSize(SizeFactor newSizeFactor) override;
    virtual SizeFactor getMinimumSizeFactor(DepthNum) const override;


private:

    void updateMyNotationSize(SizeFactor newSizeFactor);
    void updateMySize();

    void updateChildAndNotaionPosition();
    void updateLeftPos();
    void updateMyNotationPos();
    void updateRightPos();

    DepthNum getChildDepth(DepthNum myDepth) const;


    Point positionOfMyNotaion;//相对该节点左上角
    Size sizeOfMyNotation;

};

#endif // NODEHORIZONTAL_H
