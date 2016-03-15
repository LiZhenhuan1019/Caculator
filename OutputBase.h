#ifndef OutputBase_H
#define OutputBase_H
#include "GraphicsElements.h"
#include <string>

class OutputBase
{
public:

    OutputBase() = default;
    virtual ~OutputBase() = default;
    OutputBase(OutputBase const& other) = delete;
    OutputBase& operator=(OutputBase const&) = delete;

    virtual void put(std::string const&,Rect const&,SizeFactor sizefactor) = 0;
};

#endif // OutputBase_H
