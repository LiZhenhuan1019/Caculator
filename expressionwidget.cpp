#include "expressionwidget.h"
#include <QGraphicsScene>
#include <QGraphicsSimpleTextItem>
#include "Node.h"
#include "ExpressionItem.h"
#include "nodehelperinfo.h"
#include "QtDisplayHint.h"
#include "HonestExpressionDepth.h"
#include "QtGraphicsSeparator.h"
#include <c++/bits/stl_pair.h>
#include <array>
#include <utility>

#include "ui_expressionwidget.h"
using Item = QGraphicsSimpleTextItem;
class expressionCreator
{
public:
    expressionCreator(QGraphicsScene*s,NodeHelperInfo*p):scene(s),pHelper(p)
    {}


    template<typename T,typename ...ARGS>
    Expression create(ARGS&&...args)
    {
        ExpressionItem* pThis = new ExpressionItem;
        QtGraphicsSeparator* pG = new QtGraphicsSeparator;
        pG->setItem(pThis);
        DefaultNodeGeometry* ng = new DefaultNodeGeometry(pHelper,pG);

        T* p =new T(std::forward<ARGS>(args)...,ng);
        return Expression(p);
    }

//    template<typename T,typename ...ARGS>
//    Expression createMiddle(ARGS&&...args)
//    {
//        ExpressionItem* pThis = new ExpressionItem;
//        QtGraphicsSeparator* pG = new QtGraphicsSeparator;
//        pG->setItem(pThis);

//        T* p =new T(std::forward<ARGS>(args)...,pHelper,pG);

//        return Expression(p);
//    }
    template<typename T,typename ...ARGS>
    Expression createTop(ARGS&&...args)
    {
        ExpressionItem* pTop = new ExpressionItem(true);
        QtGraphicsSeparator* pG = new QtGraphicsSeparator;
        pG->setItem(pTop);
        DefaultNodeGeometry* ng = new DefaultNodeGeometry(pHelper,pG);

        T* p =new T(std::forward<ARGS>(args)...,ng);


        scene->addItem(pTop);
        return Expression(p);
    }


private:

    static ExpressionItem* createItem()
    {
        return new ExpressionItem;
    }

    QGraphicsScene*scene = nullptr;
    NodeHelperInfo *pHelper = nullptr;
};

Expression ExpressionWidget::test()
{
//    Expression ret(new NodeAdd(
//                                Expression(new NodeAdd(
//                                                        Expression(new NodeNumber(1,nodeHelper.get())),
//                                                        Expression(new NodeNumber(2,nodeHelper.get())),
//                                                        nodeHelper.get())),
//                                Expression(new NodeNumber(3,nodeHelper.get())),
//                                nodeHelper.get()));
    expressionCreator c(scene.get(),nodeHelper.get());
    return c.createTop<NodeAdd>(c.create<NodeAdd>(c.create<NodeAdd>(c.create<NodeNumber>(20),
                                                                       c.create<NodeNumber>(4)),
                                                    c.create<NodeNumber>(565)),
                                 c.create<NodeNumber>(300));

}

ExpressionWidget::ExpressionWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::expressionWidget),
    scene(new QGraphicsScene),
    nodeHelper(new NodeHelperInfo(new QtDisplayHint,new HonestExpressionDepth)),
    e(test())
{
    ui->setupUi(this);
    ui->expressionView->setScene(scene.get());
    e->updateSize(e->getMinimumSizeFactor(0));
    e->setCurrentTopLeft(Point(20,20));
    scene->update(scene->sceneRect());
    addNode(QPoint(50,50));
}

ExpressionWidget::~ExpressionWidget()
{
    delete ui;
}

void ExpressionWidget::addNode(QPoint p)
{
    Item *i = new Item;
    i->setPos(p);
    i->setText("hello  \n  hello");
    i->setFlags(QGraphicsItem::ItemIsMovable
                |QGraphicsItem::ItemIsSelectable);
    scene->addItem(i);
    i = new Item(i);

    i->setPos(10,0);
    i->setText("hello");
    i->setFlags(/*QGraphicsItem::ItemIsMovable
                |*/QGraphicsItem::ItemIsSelectable);


}
