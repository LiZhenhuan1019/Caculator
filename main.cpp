#include "mainwindow.h"
#include "expressionwidget.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    ExpressionWidget e;
    w.setCentralWidget(&e);
    w.show();

    return a.exec();
}
