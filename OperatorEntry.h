#ifndef OPERATORENTRY_H
#define OPERATORENTRY_H
#include <map>
#include <string>
struct OperatorType
{
    std::string name;
    std::size_t numberofoperations;   //操作数数量
};

class OperatorTable
{
public:
    OperatorTable();

};

#endif // OPERATORENTRY_H
