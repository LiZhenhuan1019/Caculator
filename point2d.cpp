#include "point2d.h"


/*!
    \class Point2D
    \brief Point2D 是一个用于在二维图形中表示直角坐标系中\e 点（Point） 的类模板。

    在直角坐标系中，我们用坐标的两个分量\l x （横坐标）,\l y （纵坐标）来确定点的位置。

    类模板声明：
    \code
        template <typename T = int,typename Distance = double>
        class Point2D;
    \endcode
    \c{Point2D<T>} 定义了一个点的\l {x}{横}、\l{y} {纵} 坐标。
    模板形参\a T 决定坐标分量的类型，默认实参是\c int。
    \note 对\a T 的完整要求：
    \list
    \li 能被直接复制初始化，即对于\a T 类型右值\c y ：\c{T x(y);}合法；
    \li 能以\c 0 为参数进行直接初始化，即：\c{T x(0);}合法；
    \li 对于\a T 类型左值\c a 和\a T 类型右值 \c b，以下表达式合法:
        \list
        \li \c {bool(a==0)}  （参见\l {Point2D::isNull()} ）
        \li \c {a+=b}        （参见\l {Point2D::operator+=()}）
        \li \c {a-=b}        （参见\l {Point2D::operator-=()}）
        \li \c {a*=b}        （参见\l {Point2D::operator*=()}）
        \li \c {a/=b}        （参见\l {Point2D::operator/=()}）
        \li \c {bool(a==b)}  （参见\l {operator==()}和\l {operator!=()}）
        \endlist
    \endlist

    \inmodule GeographicsTools
    \ingroup tools
    \ingroup shared
*/

/*!
    \fn Point2D::Point2D();
    对横坐标和纵坐标进行value-initialize。
*/

/*!
    \fn Point2D::Point2D(T x, T y);
    用\a x 对横坐标进行直接复制初始化，
    用\a y 对纵坐标进行直接复制初始化。
*/

/*!
    \fn T& Point2D::x();
    返回点的横坐标的左值引用。

    你可以用这个函数来读取点的横坐标，或者用返回值为横坐标设置新值。
    例如：
    \code
        Point2D<> a(3,4);
        int xOfA = a.x();  //xOfA == 3
        int yOfA = a.y();  //yOfA == 4
        a.x() = 5;         //现在a.x() == 5
        a.y() = 6;         //现在a.y() == 6
    \endcode


    \sa Point2D::y()
*/

/*!
    \fn T const& Point2D::x() const;
    \overload Point2D::x() in constness
    返回点的横坐标的常量左值引用。

    和\l Point2D::x() 不同的是，
    你\b 不能 用这个函数的返回值来为横坐标设置新值。
    例如：
    \code
        const Point2D<> a(3,4);
        int xOfA = a.x();  //xOfA == 3
        int yOfA = a.y();  //yOfA == 4
        a.x() = 5;         //error:不能给const int&类型变量赋值
        a.y() = 6;         //error:不能给const int&类型变量赋值
    \endcode


    \sa Point2D::x() ,Point2D::y()
*/

/*!
    \fn T&y();
    返回点的纵坐标的左值引用。

    你可以用这个函数来读取点的纵坐标，或者用返回值为纵坐标设置新值。
    \sa Point2D::x()
*/

/*!
    \fn T const& Point2D::y() const;
    \overload Point2D::y() in constness
    返回点的纵坐标的常量左值引用。

    和\l Point2D::y() 不同的是，
    你\b 不能 用这个函数的返回值来为纵坐标设置新值。
    \sa Point2D::x() ,Point2D::y()
*/

/*!
    \fn bool isNull() const;
    返回(Returns)\c true 如果点的横坐标、纵坐标均为\c 0 ；
    否则返回\c false .
    对模板参数\e T 的要求:
    \list
    \li 对于\c T 类型左值\c a ，以下表达式合法:
        \list
        \li \c {bool(a==0)}
        \endlist
    \endlist
*/

/*!
    \fn Distance Point2D::distanceFromOrigin()const;
    返回此点到原点的距离。
*/

/*!
    \fn Point2D<T,Distance>& Point2D::operator+=(Point2D<T,Distance> const&rhs);
    将自己的坐标自加\a rhs 的坐标,然后返回自己的引用。

    对模板参数\e T 的要求:
    \list
    \li 对于\c T 类型左值\c a 和\c T 类型右值 \c b，以下表达式合法:
        \list
        \li \c {a+=b)}
        \endlist
    \endlist
    \sa {Point2D::operator-=}
*/

/*!
    \fn Point2D<T,Distance>& Point2D::operator-=(Point2D<T,Distance> const&rhs);
    将自己的坐标自减\a rhs 的坐标,然后返回自己的引用。

    对模板参数\e T 的要求:
    \list
    \li 对于\c T 类型左值\c a 和\c T 类型右值 \c b，以下表达式合法:
        \list
        \li \c {a-=b)}
        \endlist
    \endlist
    \sa {Point2D::operator+=}
*/


/*!
    \fn Point2D<T,Distance>& Point2D::operator*=(double factor);
    将自己的坐标自乘\a factor ,然后返回自己的引用。

    对模板参数\e T 的要求:
    \list
    \li 对于\c T 类型左值\c a 和\c double 类型右值 \c b，以下表达式合法:
        \list
        \li \c {(a*=b)}
        \endlist
    \endlist
    \sa {Point2D::operator/=}
*/

/*!
    \fn Point2D<T,Distance>& Point2D::operator/=(double factor);
    将自己的坐标自除\a factor ,然后返回自己的引用。
    \note 若factor的值等于0，产生\b 未定义行为 。

    对模板参数\e T 的要求:
    \list
    \li 对于\c T 类型左值\c a 和\c double 类型右值 \c b，以下表达式合法:
        \list
        \li \c {(a/=b)}
        \endlist
    \endlist
    \sa {Point2D::operator*=}
*/

/*!
    \fn Point2D<T,Distance> operator+(Point2D<T,Distance> const&lhs,Point2D<T,Distance>const&rhs);
    \relates Point2D
    将\a lhs 的副本自加\a rhs ，然后返回这个副本。

    此函数是 \tt {Point2D<T,Distance>(\a lhs)+=\a rhs} 的快捷的方式。
    \sa {Point2D::operator+=()}
*/

/*!
    \fn Point2D<T,Distance> operator-(Point2D<T,Distance> const&lhs,Point2D<T,Distance>const&rhs);
    \relates Point2D
    将\a lhs 的副本自减\a rhs ，然后返回这个副本。

    此函数是 \tt {Point2D<T,Distance>(\a lhs)-=\a rhs} 的快捷的方式。
    \sa {Point2D::operator-=()}
*/

/*!
    \fn Point2D<T,Distance> operator*(Point2D<T,Distance> const&lhs,double factor);
    \relates Point2D
    将\a lhs 的副本自乘\a factor ，然后返回这个副本。

    此函数是 \tt {Point2D<T,Distance>(\a lhs)*=\a factor} 的快捷的方式。
    \sa {Point2D::operator*=()}
*/

/*!
    \fn Point2D<T,Distance> operator/(Point2D<T,Distance> const&lhs,double factor);
    \relates Point2D
    将\a lhs 的副本自除\a factor ，然后返回这个副本。

    此函数是 \tt {Point2D<T,Distance>(\a lhs)/=\a factor} 的快捷的方式。
    \sa {Point2D::operator/=()}
*/

/*!
    \fn bool operator==(Point2D<T,Distance> const&lhs,Point2D<T,Distance>const&rhs);
    \relates Point2D
    返回（Returns）\c true 如果\a lhs 与\a rhs 相等；
    否则返回\c false 。

    此函数是 \tt {\a {lhs}.x()==\a {rhs}.x()&&\a {lhs}.y()==\a {rhs}.y()}的快捷的方式。
    \sa {operator!=()}
*/

/*!
    \fn bool operator!=(Point2D<T,Distance> const&lhs,Point2D<T,Distance>const&rhs);
    \relates Point2D
    返回（Returns）\c true 如果\a lhs 与\a rhs 相等；
    否则返回\c false 。

    此函数是 \tt {!(\a {lhs}==\a{rhs})}的快捷的方式。
    \sa operator==()
*/

/*!
    \fn double distance(Point2D<T,Distance> const&lhs,Point2D<T,Distance>const&rhs);
    返回\a lhs 到\a rhs 的距离。

    此函数是 \tt {(\a lhs -\a rhs ).distanceFromOrigin()}的快捷的方式。
    \sa Point2D::distanceFromOrigin()
*/
