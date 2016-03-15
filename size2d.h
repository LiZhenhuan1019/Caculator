#ifndef SIZE2D_H
#define SIZE2D_H

template<typename T = int>
class Size2D
{
public:
    Size2D() = default;
    Size2D(T width,T height):mWidth(width),mHeight(height){}
    T const& width()const
    {
        return mWidth;
    }
    T& width()
    {
        return mWidth;
    }
    T const& height()const
    {
        return mHeight;
    }
    T& height()
    {
        return mHeight;
    }
    bool isEmpty()const //is null or not valid
    {
        return width()<=0||height()<=0;
    }
    bool isNull()const
    {
        return width()==0&&height()==0;
    }
    bool isValid()const
    {
        return width()>=0&&height()>=0;
    }

    Size2D<T>& operator+=(Size2D<T>const&rhs)
    {
        width()+=rhs.width();
        height()+=rhs.height();
        return *this;
    }
    Size2D<T>& operator-=(Size2D<T>const&rhs)
    {
        width()-=rhs.width();
        height()-=rhs.height();
        return *this;
    }
    Size2D<T>& operator*=(double factor)
    {
        width()*=factor;
        height()*=factor;
        return *this;
    }
    Size2D<T>& operator/=(double factor)
    {
        width()/=factor;
        height()/=factor;
        return *this;
    }

protected:
    T mWidth = 0;
    T mHeight = 0;
};
template<typename T>
Size2D<T> operator+(Size2D<T> const&lhs,Size2D<T>const&rhs)
{
    return Size2D<T>(lhs)+=rhs;
}
template<typename T>
Size2D<T> operator-(Size2D<T>const&lhs,Size2D<T>const&rhs)
{
    return Size2D<T>(lhs)-=rhs;
}
template<typename T>
Size2D<T> operator*(Size2D<T>const&lhs,double factor)
{
    return Size2D<T>(lhs)*=factor;
}
template<typename T>
Size2D<T> operator/(Size2D<T>const&lhs,double factor)
{
    return Size2D<T>(lhs)/=factor;
}
template<typename T>
bool operator==(Size2D<T> const&lhs,Size2D<T>const&rhs)
{
    return lhs.width()==rhs.width()&&lhs.height()==rhs.height();
}
template<typename T>
bool operator!=(Size2D<T> const&lhs,Size2D<T>const&rhs)
{
    return !(lhs==rhs);
}


#endif // SIZE2D_H
