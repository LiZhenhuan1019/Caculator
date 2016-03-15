#include "NodeNumber.h"
#include "nodehelperinfo.h"
#include "displayhint.h"
#include <string>




std::string NodeNumber::notation() const
{
    return std::to_string(num);
}


SizeFactor NodeNumber::getMinimumSizeFactor(DepthNum) const
{
    return getNodeHelper()->pDisplayHint->defaultNumberSizeFactor();
}
long long NodeNumber::getNumber() const
{
    return num;
}

void NodeNumber::setNumber(long long value)
{
        num = value;
}



