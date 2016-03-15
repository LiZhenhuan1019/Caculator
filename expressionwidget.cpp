#include "expressionwidget.h"
#include <QGraphicsScene>
#include <QGraphicsSimpleTextItem>
#include "Node.h"
#include "QtExpressionItem.h"
#include "nodehelperinfo.h"
#include "QtDisplayHint.h"
#include "HonestExpressionDepth.h"
#include "QtGraphicsSeparator.h"
#include <c++/bits/stl_pair.h>
#include <array>
#include <utility>

#include "ui_expressionwidget.h"





class expressionCreator
{
public:
    expressionCreator(QGraphicsScene*s,NodeHelperInfo*p,NodeBag&nodebag,NodeGuiBag&guibag)
        :scene(s),pHelper(p),nodeBag(nodebag),guiBag(guibag)
    {}


    template<typename T,typename ...ARGS>
    Expression create(ARGS&&...args)
    {
        ExpressionItem* pThis = new ExpressionItem;
        QtGraphicsSeparator* pG = new QtGraphicsSeparator;
        pG->setItem(pThis);
        DefaultNodeGeometry* gui = new DefaultNodeGeometry(pHelper,pG);

        T* p =new T(std::forward<ARGS>(args)...,gui);
        setID(p,gui);
        nodeBag.addNode(p);
        guiBag.addGuiItem(gui);
        return Expression(p);
    }

    template<typename T,typename ...ARGS>
    void createTop(ARGS&&...args)
    {
        ExpressionItem* pTop = new ExpressionItem(true);
        QtGraphicsSeparator* pG = new QtGraphicsSeparator;
        pG->setItem(pTop);
        DefaultNodeGeometry* gui = new DefaultNodeGeometry(pHelper,pG);

        T* p =new T(std::forward<ARGS>(args)...,gui);
        setID(p,gui);
        nodeBag.setTopExpression(Expression(p));
        guiBag.addGuiItem(gui);
        scene->addItem(pTop);
    }

private:
    void setID(NodeBase*node,DefaultNodeGeometry*gui)
    {
        node->id=gui->id=idCounter++;
    }

    QGraphicsScene*scene = nullptr;
    NodeHelperInfo *pHelper = nullptr;
    NodeBag& nodeBag;
    NodeGuiBag& guiBag;
    int idCounter = 0;
};

std::pair<NodeBag,NodeGuiBag> ExpressionWidget::getTestExpression()
{
    NodeBag nodeBag;
    NodeGuiBag guiBag;
    expressionCreator c(scene.get(),nodeHelper.get(),nodeBag,guiBag);
    c.createTop<NodeAdd>(c.create<NodeAdd>(c.create<NodeAdd>(c.create<NodeNumber>(20),
                                                                       c.create<NodeNumber>(4)),
                                                    c.create<NodeNumber>(565)),
                                 c.create<NodeNumber>(300));
    return {std::move(nodeBag),std::move(guiBag)};
}

ExpressionWidget::ExpressionWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::expressionWidget),
    scene(new QGraphicsScene),
    nodeHelper(new NodeHelperInfo(new QtDisplayHint,new HonestExpressionDepth))
{
    ui->setupUi(this);
    ui->expressionView->setScene(scene.get());
    auto bags=getTestExpression();
    nodeBag=std::move(bags.first);
    guiBag=bags.second;
    NodeBase *top = nodeBag.getTopExpression();
    top->updateSize(top->getMinimumSizeFactor(0));
    top->setCurrentTopLeft(Point(20,20));
    scene->update(scene->sceneRect());
    addHello(QPoint(50,50));
}

ExpressionWidget::~ExpressionWidget()
{
    delete ui;
}

using Item = QGraphicsSimpleTextItem;
void ExpressionWidget::addHello(QPoint p)
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
