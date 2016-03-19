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
    NodeHorizontal(Expression&& el,Expression&& er,NodeGuiBag *gui, NodeID id)
        :NodeBinary(std::move(el),std::move(er),gui,id)
    {}

    NodeHorizontal(NodeBase* pl,NodeBase* pr,NodeGuiBag *gui, NodeID id)
      :NodeHorizontal(Expression(pl),Expression(pr),gui,id)
    {}
//#ifdef DEBUG
//    virtual size_t size() const override
//    {
//        return left.get()->size()+right.get()->size();
//    }
//    virtual std::string nodeName() const override
//    {
//        return "NodeHorizontal";
//    }
//    virtual void print(std::ostream& o,size_t line) const override
//    {
//        std::string str1(" with left:");
//        std::string str2(" with right:");
//        assert(line<size());
//        if(line==0)
//        {
//            o<<nodeidentity();
//            printExpr(o,left,line,str1);
//        }
//        else if(line<left.get()->size())
//        {
//            printspace(o,nodeidentity().size());
//            printExpr(o,left,line,str1);
//        }
//        else
//        {
//            printspace(o,nodeidentity().size());
//            printExpr(o,right,line-left.get()->size(),str2);
//        }
//    }
//#endif // DEBUG
    virtual void display(OutputBase &o,Point topLeft) const override;
//    virtual bool isSizeUpdated()const override;
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
