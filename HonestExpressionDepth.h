#ifndef HONESTEXPRESSIONDEPTH_H
#define HONESTEXPRESSIONDEPTH_H
#include "expressiondepth.h"

class HonestExpressionDepth : public ExpressionDepth
{
public:
    HonestExpressionDepth() = default;

    virtual DepthNum getChildDepth(DepthNum cur) const override;
};

#endif // HONESTEXPRESSIONDEPTH_H
