#ifndef RECT2D_H
#define RECT2D_H
#include "point2d.h"
#include "size2d.h"

template<typename T = int>
class Rect2D
{
public:
    Rect2D() = default;
    Rect2D(Point2D<T> const&p,Size2D<T> const&s)
        :mTopLeft(p),mSize(s)
    {}
    Rect2D(T x,T y,T width,T height)
        :mTopLeft(x,y),mSize(width,height)
    {}

    Point2D<T> topLeft() const
    {
        return mTopLeft;
    }
    void setTopLeft(Point2D<T> const&p)
    {
        mTopLeft = p;
    }

    Size2D<T> size() const
    {
        return mSize;
    }
    void setSize(Size2D<T> const& s)
    {
        mSize = s;
    }

    T left() const
    {
        return mTopLeft.x();
    }
    void setLeft(T l)
    {
        T differ = mTopLeft.x()-l;
        mTopLeft.x() = l;
        mSize.width()+=differ;
    }

    T right() const
    {
        return mTopLeft.x()+mSize.width();
    }
    void setRight(T r)
    {
        mSize.width()=r-mTopLeft.x();
    }

    T top() const
    {
        return mTopLeft.y();
    }
    void setTop(T t)
    {
        T differ= mTopLeft.y()-t;
        mTopLeft.y() = t;
        mSize.height()+=differ;
    }

    T bottom() const
    {
        return mTopLeft.y()+mSize.height();
    }
    void setBottom(T b)
    {
        mSize.height()=b-mTopLeft.y();
    }



private:
    Point2D<T> mTopLeft;
    Size2D<T> mSize;
};

template <typename T>
Rect2D<T> operator+(Rect2D<T> const&lhs,Point2D<T> const&rhs)
{
    return Rect2D<T>(lhs.topLeft()+rhs,lhs.size());
}

template <typename T>
bool operator==(Rect2D<T> const&lhs,Rect2D<T> const&rhs)
{
    return lhs.mTopLeft==rhs.mTopLeft&&lhs.mSize==rhs.mSize;
}

template <typename T>
bool operator!=(Rect2D<T> const&lhs,Rect2D<T> const&rhs)
{
    return !(lhs==rhs);
}

#endif // RECT2D_H
