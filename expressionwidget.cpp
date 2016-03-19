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
}

ExpressionWidget::~ExpressionWidget()
{
    delete ui;
}
