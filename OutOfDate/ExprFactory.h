#ifndef EXPRFACTORY_H
#define EXPRFACTORY_H
#include "caculatorheader.h"
#include "expression.h"
#include "Node.h"
//用于产生节点
class ExprFactory
{
public:
    ExprFactory();
    ~ExprFactory();
    void test()
    {
        Expression e(
            new Node_subtract(new Node_multi(new Node_number(10),
                                      new Node_number(11)),
                         new Node_number(12)));
        traceOut(std::cout,e);
    }

#ifdef DEBUG
    template<typename OUT,typename EXPR>
    class Trace
    {
    public:
        Trace(OUT& o):outfile(o)
        {

        }
        Trace& operator<<(EXPR const& expr)
        {
            std::string str0="Head Node:";
            /*
            outfile<<str0;
            expr.print(outfile,0);
            outfile<<"\n";
            for(size_t line=1;line<expr.size();++line)
            {
                printspace(outfile,str0.size());
                expr.print(outfile,line);
            }*/
            for(size_t line=0;line<expr.get()->size();++line)
            {
                printExpr(outfile,expr,line,str0);
                outfile<<"\n";
            }
            return *this;
        }
    protected:
        OUT& outfile;
    };
    template<typename OUT,typename EXPR>
    void traceOut(OUT& o,EXPR const& e)
    {
        Trace<OUT,EXPR>(o)<<e;
    }
#endif // DEBUG
};

#endif // EXPRFACTORY_H

