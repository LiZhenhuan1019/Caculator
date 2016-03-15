#ifndef EXPRESSIONDEPTH_H
#define EXPRESSIONDEPTH_H


class ExpressionDepth
{
public:
    using DepthNum = int;

    ExpressionDepth()= default;

    virtual DepthNum getChildDepth(DepthNum cur) const = 0;
};

#endif // EXPRESSIONDEPTH_H
