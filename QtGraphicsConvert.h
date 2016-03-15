#ifndef QTGRAPHICSCONVERT
#define QTGRAPHICSCONVERT
#include "point2d.h"
#include "size2d.h"
#include "rect2d.h"
#include "QPointF"
#include "QSizeF"
#include "QRectF"
template <typename T>
QPointF toQPointF(Point2D<T> const& p)
{
    return QPointF(p.x(),p.y());
}

template <typename T>
QSizeF toQSizeF(Size2D<T> const s)
{
    return QSizeF(s.width(),s.height());
}

template <typename T>
QRectF toRectF(Rect2D<T> const r)
{
    return QRect(r.left(),r.top(),r.size().width(),r.size().height());
}

#endif // QTGRAPHICSCONVERT

