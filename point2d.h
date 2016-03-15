#ifndef POINT2D_H
#define POINT2D_H


template <typename T = int,typename Distance = double>
class Point2D
{
public:
    Point2D() = default;
    Point2D(T x,T y):mx(x),my(y)
    {}
    T& x()
    {
        return mx;
    }
    T const& x() const
    {
        return mx;
    }
    T& y()
    {
        return my;
    }
    T const& y() const
    {
        return my;
    }
    bool isNull() const
    {
        return x()==0&&y()==0;
    }

    Distance distanceFromOrigin() const
    {
        return x()*x()+y()*y();
    }

    Point2D<T,Distance>& operator+=(Point2D<T,Distance> const&rhs)
    {
        x()+=rhs.x();
        y()+=rhs.y();
        return *this;
    }
    Point2D<T,Distance>& operator-=(Point2D<T,Distance> const&rhs)
    {
        x()-=rhs.x();
        y()-=rhs.y();
        return *this;
    }
    Point2D<T,Distance>& operator*=(double factor)
    {
        x()*=factor;
        y()*=factor;
        return *this;
    }
    Point2D<T,Distance>& operator/=(double factor)
    {
        x()/=factor;
        y()/=factor;
        return *this;
    }


private:
    T mx{};
    T my{};
};

template<typename T,typename Distance>
Point2D<T,Distance> operator+(Point2D<T,Distance> const&lhs,Point2D<T,Distance>const&rhs)
{
    return Point2D<T,Distance>(lhs)+=rhs;
}
template<typename T,typename Distance>
Point2D<T,Distance> operator-(Point2D<T,Distance>const&lhs,Point2D<T,Distance>const&rhs)
{
    return Point2D<T,Distance>(lhs)-=rhs;
}
template<typename T,typename Distance>
Point2D<T,Distance> operator*(Point2D<T,Distance>const&lhs,double factor)
{
    return Point2D<T,Distance>(lhs)*=factor;
}
template<typename T,typename Distance>
Point2D<T,Distance> operator/(Point2D<T,Distance>const&lhs,double factor)
{
    return Point2D<T,Distance>(lhs)/=factor;
}
template<typename T,typename Distance>
bool operator==(Point2D<T,Distance> const&lhs,Point2D<T,Distance>const&rhs)
{
    return lhs.x()==rhs.x()&&lhs.y()==rhs.y();
}
template<typename T,typename Distance>
bool operator!=(Point2D<T,Distance> const&lhs,Point2D<T,Distance>const&rhs)
{
    return !(lhs==rhs);
}

template<typename T,typename Distance>
double distance(Point2D<T,Distance> const&lhs,Point2D<T,Distance>const&rhs)
{
    return (lhs-rhs).distanceFromOrigin();
}


#endif // POINT2D_H
