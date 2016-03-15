#ifndef EXPRESSIONITEM_H
#define EXPRESSIONITEM_H
#include <QGraphicsItem>
#include <QCoreApplication>
#include "DefaultGraphicsSeparator.h"
class NodeBase;
class ExpressionItem : public QGraphicsItem
{
    Q_DECLARE_TR_FUNCTIONS(ExpressionItem)

public:
    ExpressionItem(bool movable = false,DefaultGraphicsSeparator<ExpressionItem>*pG = nullptr,QGraphicsItem *pParent = nullptr)
        :QGraphicsItem(pParent),separator(pG)
    {
        if(movable)
        {
            setFlag(ItemIsMovable,true);
        }
        setFlag(ItemIsSelectable,true);
    }

    virtual QRectF boundingRect()const override;
    virtual void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *)override;
    using QGraphicsItem::prepareGeometryChange;


    DefaultGraphicsSeparator<ExpressionItem> *getseparator() const;
    void setseparator(DefaultGraphicsSeparator<ExpressionItem> *value);

    DefaultNodeGeometry *node() const;
private:


    QRectF boudingRectWithTopLeftIsZero()const;

    DefaultGraphicsSeparator<ExpressionItem>* separator = nullptr;
};

#endif // EXPRESSIONITEM_H
