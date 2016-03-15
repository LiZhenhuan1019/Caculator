#include "HonestExpressionDepth.h"




ExpressionDepth::DepthNum HonestExpressionDepth::getChildDepth(ExpressionDepth::DepthNum cur) const
{
    return cur + 1;
}
