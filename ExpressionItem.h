#ifndef EXPRESSIONITEM_H
#define EXPRESSIONITEM_H
#include <QGraphicsItem>
#include <QCoreApplication>
#include "GraphicsSeparator.h"
class NodeBase;
class ExpressionItem : public QGraphicsItem
{
    Q_DECLARE_TR_FUNCTIONS(ExpressionItem)

public:
    ExpressionItem(bool movable = false,GraphicsSeparator<ExpressionItem>*pG = nullptr,QGraphicsItem *pParent = nullptr)
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


    GraphicsSeparator<ExpressionItem> *getseparator() const;
    void setseparator(GraphicsSeparator<ExpressionItem> *value);

    DefaultNodeGeometry *node() const;
private:


    QRectF boudingRectWithTopLeftIsZero()const;

    GraphicsSeparator<ExpressionItem>* separator = nullptr;
};

#endif // EXPRESSIONITEM_H
