#include "NodeFinal.h"
#include "OutputBase.h"
#include "nodehelperinfo.h"
#include "displayhint.h"
#include "DefaultGraphicsSeparator.h"


void NodeFinal::display(OutputBase &o,Point topLeft) const
{
    SizeFactor f = getFactorOfCurrentSize();
    o.put(notation(),Rect(topLeft,getCurrentSize()),f);
}

//bool NodeFinal::isSizeUpdated() const
//{
//    return mIsSizeUpdated;
//}

void NodeFinal::updateSize(SizeFactor sizeFactor)
{
    NodeBase::updateSize(sizeFactor);
    setFactorOfCurrentSize(sizeFactor);
    setCurrentSize(getNodeHelper()
             ->pDisplayHint
             ->sizeHint(notation(),getFactorOfCurrentSize()));
}

