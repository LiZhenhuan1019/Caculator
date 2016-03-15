#include "caculatorheader.h"
#include "QtExpressionItem.h"
#include "NodeBase.h"
#include "QtPaintOutput.h"
#include <QPainter>
#include <QStyleOptionGraphicsItem>
#include "NodeGuiItem.h"

QRectF ExpressionItem::boundingRect() const
{
    QRectF r = boudingRectWithTopLeftIsZero();
    return r.translated(-r.center());
}

DefaultNodeGeometry *ExpressionItem::node() const
{
    return separator->getNodeGeometry();
}


void ExpressionItem::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget */*widget*/)
{
    QtPaintOutput p(painter);
    if (option->state&QStyle::State_Selected)
    {
        painter->save();
        QPen p(QColor(128,128,255));
        p.setWidth(2);
        painter->setPen(p);
        painter->drawRect(boundingRect());
        painter->restore();
    }
    else
    {
        GRAPHICSDEBUG(painter->save());
        GRAPHICSDEBUG(painter->setPen(QColor(255,0,0)));
        //GRAPHICSDEBUG(painter->drawEllipse(QPoint(0,0),5,5));
        GRAPHICSDEBUG(painter->drawRect(boundingRect()));
        GRAPHICSDEBUG(painter->restore());
    }

    Size size=node()->getCurrentSize();
    node()->display(p,Point(-size.width()/2,-size.height()/2));
    //GRAPHICSDEBUG(painter->drawEllipse(QPoint(-size.width()/2,-size.height()/2),5,5));
}


QRectF ExpressionItem::boudingRectWithTopLeftIsZero() const
{
    if(!separator||!node())
    {
        return QRectF();
    }
    else
    {
        Size size=node()->getCurrentSize();
        return QRectF(0,0,size.width(),size.height());
    }
}
DefaultGraphicsSeparator<ExpressionItem> *ExpressionItem::getseparator() const
{
    return separator;
}

void ExpressionItem::setseparator(DefaultGraphicsSeparator<ExpressionItem> *value)
{
    separator = value;
}


