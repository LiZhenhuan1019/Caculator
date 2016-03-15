#ifndef COPYABLE_UNIQUE_PTR_H
#define COPYABLE_UNIQUE_PTR_H
#include <c++/bits/unique_ptr.h>
template <typename _Tp, typename _Dp = std::default_delete<_Tp> >
class copyable_unique_ptr:public std::unique_ptr<_Tp,_Dp>
{
public:
    copyable_unique_ptr() = default;
    using std::unique_ptr<_Tp,_Dp>::unique_ptr;
    copyable_unique_ptr(copyable_unique_ptr const&src)
        :std::unique_ptr<_Tp,_Dp>(new _Tp(*src))
    {}
    copyable_unique_ptr(copyable_unique_ptr&&src) = default;
    copyable_unique_ptr& operator=(copyable_unique_ptr const&src) = default;
    copyable_unique_ptr& operator=(copyable_unique_ptr&&src) = default;
};

#endif // COPYABLE_UNIQUE_PTR_H
