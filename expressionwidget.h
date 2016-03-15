#ifndef EXPRESSIONWIDGET_H
#define EXPRESSIONWIDGET_H
#include "expression.h"
#include <c++/bits/unique_ptr.h>
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

    Expression test();
private:
    void addNode(QPoint p);

    Ui::expressionWidget *ui;
    std::unique_ptr<QGraphicsScene> scene;
    std::unique_ptr<NodeHelperInfo> nodeHelper;
    Expression e;
};

#endif // EXPRESSIONWIDGET_H
