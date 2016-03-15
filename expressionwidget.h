#ifndef EXPRESSIONWIDGET_H
#define EXPRESSIONWIDGET_H
#include "expression.h"
#include "NodeBag.h"
#include "NodeGUIBag.h"
#include <memory>
#include <QWidget>
class QGraphicsScene;
namespace Ui {
    class expressionWidget;
}

class ExpressionWidget : public QWidget
{
    Q_OBJECT

public:
    explicit ExpressionWidget(QWidget *parent = 0);
    ~ExpressionWidget();

    std::pair<NodeBag,NodeGuiBag> getTestExpression();
private:
    void addHello(QPoint p);

    Ui::expressionWidget *ui;
    std::unique_ptr<QGraphicsScene> scene;
    std::unique_ptr<NodeHelperInfo> nodeHelper;
    NodeBag nodeBag;
    NodeGuiBag guiBag;
};

#endif // EXPRESSIONWIDGET_H
