#ifndef NODEBASE_H
#define NODEBASE_H
#include "caculatorheader.h"
#include "GraphicsElements.h"
#include "GraphicsSeparatorDeclarations.h"
#include "NodeGeometryDeclaration.h"
#include <copyable_unique_ptr.h>
#include <string>
#include <assert.h>

//结点始终保持自己的currentSize与factorOfCurrentSize一致。默认情况下使用
//getMinimumSizeFactor的结果来计算这两者，除非调用了updateSize（此时这两者都根据参数重新计算）
//在updateSize调用期间，正确的factor并不意味着正确的size。
//比如替换了新结点后，factor未变，size（包括其所有父节点的）却可能需要更新。
//此时父节点的size不正确。


class OutputBase;
class Expression;
class NodeHelperInfo;
class NodeBase
{
public:

    friend class Expression;
    //friend class ExprFactory;
    friend class OperatorTable;

    NodeBase() = default;
    NodeBase(DefaultNodeGeometry *geo);

    virtual ~NodeBase();
    NodeBase& operator=(const NodeBase& other) = delete;

    virtual NodeBase* copy() const = 0;

public:
    virtual void display(OutputBase &o,Point topLeft) const = 0;
    virtual std::string notation() const = 0;

    Point getCurrentTopLeft() const;//相对父节点左上角位置，即父节点左上角为(0,0)
    void setCurrentTopLeft(const Point &value,Size const&parentSize = Size(0,0));
    Size getCurrentSize() const;
    void setCurrentSize(Size newSize);
    SizeFactor getFactorOfCurrentSize() const;
    void setFactorOfCurrentSize(SizeFactor s);
    virtual SizeFactor getMinimumSizeFactor(DepthNum) const = 0;
    //virtual size_t numberOfOperations() const = 0;


//    virtual bool isSizeUpdated()const = 0;

    virtual void updateSize(SizeFactor sizeFactor);


    DefaultGraphicsSeparator *getGraphicsItem() const;
    void setGraphicsItem(DefaultGraphicsSeparator *value);
    NodeHelperInfo *getNodeHelper() const;
    void setNodeHelper(NodeHelperInfo *value);

protected:
    copyable_unique_ptr<DefaultNodeGeometry> geometry;

};

#endif // NODEBASE_H
