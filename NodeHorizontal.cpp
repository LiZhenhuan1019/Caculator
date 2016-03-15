#include "NodeHorizontal.h"
#include <algorithm>
#include "nodehelperinfo.h"
#include "OutputBase.h"
#include "displayhint.h"
#include "expressiondepth.h"
#include "DefaultGraphicsSeparator.h"
namespace NodeHorizontal_impl
{
    const int leftPadding = 5;
    const int rightPadding = 5;
    const int middlePadding = 5;
    const int topPadding = 5;
    const int bottomPadding = 5;
    const SizeFactor factorDiffer = 8;


    SizeFactor computSizeFactorOfChildNode(SizeFactor myFactor)
    {
        return myFactor-factorDiffer;
    }
    SizeFactor computeMySizeFactorFromChildFactor(SizeFactor childFactor)
    {
        return childFactor+factorDiffer;
    }

    Point computeLeftChildPos(Size const&mySize,Size const&leftSize)
    {
        return Point(0,(mySize.height()-leftSize.height())/2);//垂直方向上居中
    }
    Point computeRightChildPoint(Point const&myNotationPos,Size const&notationSize)
    {
        return myNotationPos+Point(notationSize.width()+middlePadding,0);
    }

//    Size computeSize(Size const&left,Size const&middle,Size const& right)
//    {
//        Size ret;
//        ret.width()=leftPadding
//                    +left.width()
//                    +middlePadding
//                    +middle.width()
//                    +middlePadding
//                    +right.width()
//                    +rightPadding;
//        ret.height() =topPadding
//                      +std::max
//                       (
//                           std::max
//                           (
//                               left.height(),middle.height()
//                           ),
//                           right.height()
//                       )
//                      +bottomPadding;
//        return ret;
//    }
}


void NodeHorizontal::display(OutputBase &o,Point topLeft) const
{
    using namespace NodeHorizontal_impl;
    o.put(notation(),
          Rect(positionOfMyNotaion+topLeft,sizeOfMyNotation),
          getFactorOfCurrentSize()
          );
}

//bool NodeHorizontal::isSizeUpdated() const
//{
//    return left->isSizeUpdated()&&right->isSizeUpdated();
//}


void NodeHorizontal::updateLeftPos()
{
    using namespace NodeHorizontal_impl;
    Size leftSize = left->getCurrentSize();
    left->setCurrentTopLeft(Point(leftPadding,(getCurrentSize().height()-topPadding-bottomPadding-leftSize.height())/2+topPadding),getCurrentSize());
}

void NodeHorizontal::updateMyNotationPos()
{
    using namespace NodeHorizontal_impl;
    Point leftPos = left->getCurrentTopLeft();
    Size leftSize = left->getCurrentSize();
    positionOfMyNotaion = Point(leftPos.x()+leftSize.width()+middlePadding,
                                (getCurrentSize().height()-topPadding-bottomPadding-sizeOfMyNotation.height())/2+topPadding);
}

void NodeHorizontal::updateRightPos()
{
    using namespace NodeHorizontal_impl;
    Size rightSize = right->getCurrentSize();
    right->setCurrentTopLeft(Point(positionOfMyNotaion.x()+sizeOfMyNotation.width()+middlePadding,
                                   (getCurrentSize().height()-topPadding-bottomPadding-rightSize.height())/2+topPadding),getCurrentSize());
}



void NodeHorizontal::updateChildAndNotaionPosition()
{
    using namespace NodeHorizontal_impl;
    updateLeftPos();
    updateMyNotationPos();
    updateRightPos();
}

void NodeHorizontal::updateMyNotationSize(SizeFactor newSizeFactor)
{
    setFactorOfCurrentSize(newSizeFactor);
    sizeOfMyNotation = getNodeHelper()
                       ->pDisplayHint
                       ->sizeHint(notation(),getFactorOfCurrentSize());
}

void NodeHorizontal::updateMySize()
{
    using namespace NodeHorizontal_impl;


    Size l = left->getCurrentSize();
    Size r = right->getCurrentSize();
    Size newSize;
    newSize.width() = leftPadding
                          +l.width()
                          +middlePadding
                          +sizeOfMyNotation.width()
                          +middlePadding
                          +r.width()
                          +rightPadding;
    newSize.height() = topPadding
                           +std::max
                            (
                                std::max
                                (
                                    l.height(),sizeOfMyNotation.height()
                                )
                                ,r.height()
                            )
                            +bottomPadding;
    setCurrentSize(newSize);
}

void NodeHorizontal::updateSize(SizeFactor newSizeFactor)
{
    using namespace NodeHorizontal_impl;
    NodeBase::updateSize(newSizeFactor);

    SizeFactor newChildSizeFactor = computSizeFactorOfChildNode(newSizeFactor);
    left->updateSize(newChildSizeFactor);
    right->updateSize(newChildSizeFactor);
    if(getFactorOfCurrentSize() != newSizeFactor)
    {
        updateMyNotationSize(newSizeFactor);
    }
    updateMySize();
    updateChildAndNotaionPosition();
}

SizeFactor NodeHorizontal::getMinimumSizeFactor(DepthNum n)const
{
    using namespace NodeHorizontal_impl;
    //使用者调用updateSize时其参数不得小于此，所以是minimum
    return computeMySizeFactorFromChildFactor(std::max(left->getMinimumSizeFactor(getChildDepth(n)),
                                                       right->getMinimumSizeFactor(getChildDepth(n))));
}

DepthNum NodeHorizontal::getChildDepth(DepthNum myDepth) const
{
    return getNodeHelper()->pExpressionDepth->getChildDepth(myDepth);
}



