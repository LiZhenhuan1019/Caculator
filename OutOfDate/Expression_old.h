#ifndef EXPRESSION_H
#define EXPRESSION_H
#include "Node_base.h"
namespace Old{


    class Expression
    {
        using SizeFactor=Node_base::SizeFactor;
    public:
        Expression() = default;
        explicit Expression(Node_base* p):pResource(p)
        {}
        Expression(const Expression& other):pResource(other.getCopy())
        {}
        Expression(Expression&& other):pResource(other.release())
        {}
        Expression& operator=(const Expression& other)
        {
            if (this == &other)
                return *this;
            destroy();
            pResource = other.getCopy();
        }
        Expression& operator=(Expression&& other)
        {
            if(this == &other)
                return *this;
            destroy();
            pResource = other.release();
        }
        ~Expression()
        {
            destroy();
        }

        SizeFactor getSizeFactor()const
        {
            return pResource->getSizeFactor();
        }

#ifdef DEBUG
        size_t size() const
        {
            return pResource->size();
        }
        void print(std::ostream& o,size_t line) const
        {
            pResource->print(o,line);
        }
#endif // DEBUG
    protected:
        void destroy()
        {
            delete pResource;
        }
        Node_base* getCopy() const
        {
            return pResource->copy();
        }
        Node_base* release()
        {
            Node_base* p=pResource;
            pResource=nullptr;
            return p;
        }

        Node_base *pResource=nullptr;
    };
}

#endif // EXPRESSION_H
