#ifndef EXPRESSION_H
#define EXPRESSION_H
//#include <bits/unique_ptr.h>
#include "NodeBase.h"


class Expression : public std::unique_ptr<NodeBase>
{
public:
    Expression()=default;
    using std::unique_ptr<NodeBase>::unique_ptr;
    Expression(Expression const& src)
        :unique_ptr<NodeBase>(src->copy())
    {
        assert(false);
    }
    Expression(Expression&& src) = default;
    Expression& operator=(Expression const&src) = delete;
    Expression& operator=(Expression &&src)
    {
        unique_ptr<NodeBase>::operator =(std::move(src));
        return *this;
    }
};

#endif // EXPRESSION_H
