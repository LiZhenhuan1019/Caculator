#include "NodeFinal.h"
#include "OutputBase.h"
#include "nodehelperinfo.h"
#include "displayhint.h"
#include "GraphicsSeparator.h"


void NodeFinal::display(OutputBase &o,Point topLeft) const
{
    SizeFactor f = getFactorOfCurrentSize();
    o.put(notation(),Rect(topLeft,getCurrentSize()),f);
}


void NodeFinal::updateSize(SizeFactor sizeFactor)
{
    NodeBase::updateSize(sizeFactor);
    setFactorOfCurrentSize(sizeFactor);
    setCurrentSize(getNodeHelper()
             ->pDisplayHint
             ->sizeHint(notation(),getFactorOfCurrentSize()));
}

