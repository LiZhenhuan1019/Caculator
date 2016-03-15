#ifndef INDENTOUTPUTHEARDER
#define INDENTOUTPUTHEARDER
#include <sstream>
#include <iostream>
using std::size_t;
//  Has been deprecated
#ifdef DEBUG
template <typename OUT>
inline void printspace(OUT& o,size_t number)
{
    for(size_t i=0; i<number; ++i)
        o<<" ";
}
template <typename OUT,typename EXPR,typename STR>
inline void printExpr(OUT& o,EXPR const& e,size_t line,STR const& firstline)
{
    if(line==0)
    {
        o<<firstline;
    }
    else
        printspace(o,firstline.size());
    e.get()->print(o,line);
}
inline std::string size_ttostring(size_t i)
{
    std::ostringstream s;
    s<<i;
    return s.str();
}
#endif // DEBUG


#endif // INDENTOUTPUTHEARDER

