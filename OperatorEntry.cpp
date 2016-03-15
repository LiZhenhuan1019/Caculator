#include "Node.h"
#include "OperatorEntry.h"
#include <vector>
#include <iostream>
//#include "Node_base.h"


OperatorTable::OperatorTable()
{
    std::vector<size_t*> table[]=
    {
        {},
        {&NodeMulti::ilevel,&NodeDivide::ilevel},
        {&NodeAdd::ilevel,&NodeSubtract::ilevel},
        {}
    };
    for(int i = 0;i<end(table)-begin(table);++i)
    {
        for(auto&p:table[i])
        {
            *p=i;
        }
    }
}
