#ifndef NODEHELPERINFO_H
#define NODEHELPERINFO_H
#include <c++/bits/unique_ptr.h>
#include "displayhint.h"
#include"expressiondepth.h"
class DisplayHint;
class ExpressionDepth;
class NodeHelperInfo
{
public:
    NodeHelperInfo() = default;
    NodeHelperInfo(DisplayHint*pd,ExpressionDepth*pe)
        :pDisplayHint(pd),pExpressionDepth(pe)
    {}

    std::unique_ptr<DisplayHint> pDisplayHint;
    std::unique_ptr<ExpressionDepth> pExpressionDepth;
};

#endif // NODEHELPERINFO_H
