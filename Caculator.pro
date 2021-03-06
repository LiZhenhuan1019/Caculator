#-------------------------------------------------
#
# Project created by QtCreator 2015-07-16T21:43:58
#
#-------------------------------------------------



QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Caculator
TEMPLATE = app

include(..\..\my-include.pro)


SOURCES += mainwindow.cpp \
    consoleOutput.cpp \
    displayhint.cpp \
    Node.cpp \
    NodeHorizontal.cpp \
    NodeDivide.cpp \
    OperatorEntry.cpp \
    size2d.cpp \
    expression.cpp\
    main.cpp \
    expressiondepth.cpp \
    QtDisplayHint.cpp \
    nodehelperinfo.cpp \
    expressionwidget.cpp \
    point2d.cpp \
    rect2d.cpp \
    HonestExpressionDepth.cpp \
    QtPaintOutput.cpp \
    NodeBase.cpp \
    NodeAdd.cpp \
    NodeFinal.cpp \
    NodeMulti.cpp \
    NodeNumber.cpp \
    NodeSubtract.cpp \
    NodeUnary.cpp \
    NodeBinary.cpp \
    QtGraphicsSeparator.cpp \
    copyable_unique_ptr.cpp \
    OutputBase.cpp \
    NodeID.cpp \
    DefaultGraphicsSeparator.cpp \
    NodeBag.cpp \
    NodeGuiBag.cpp \
    QtExpressionItem.cpp

HEADERS  += mainwindow.h \
    consoleOutput.h \
    displayhint.h \
    Node.h \
    NodeHorizontal.h \
    NodeDivide.h \
    OperatorEntry.h \
    size2d.h \
    expression.h\
    caculatorheader.h \
    expressiondepth.h \
    QtDisplayHint.h \
    indentoutputhearder.h \
    nodehelperinfo.h \
    expressionwidget.h \
    point2d.h \
    rect2d.h \
    HonestExpressionDepth.h \
    QtPaintOutput.h \
    GraphicsElements.h \
    QtGraphicsConvert.h \
    NodeBase.h \
    NodeAdd.h \
    NodeFinal.h \
    NodeMulti.h \
    NodeNumber.h \
    NodeSubtract.h \
    NodeUnary.h \
    NodeBinary.h \
    GraphicsSeparatorDeclarations.h \
    QtGraphicsSeparator.h \
    copyable_unique_ptr.h \
    NodeGuiItem.h \
    OutputBase.h \
    NodeBaseDeclaration.h \
    NodeID.h \
    DefaultGraphicsSeparator.h \
    NodeBag.h \
    NodeGuiBag.h \
    NodeGuiDeclaration.h \
    QtExpressionItem.h

FORMS    += mainwindow.ui \
    expressionwidget.ui

DISTFILES += \
    doc/about some virtual functions in the Node_base class \
    doc/AboutSomeVirtualFunctionsInTheNode_baseClass.txt \
    doc/AboutThoseDeprecated.txt
