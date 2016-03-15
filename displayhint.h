#ifndef DISPLAYHINT_H
#define DISPLAYHINT_H
#include "GraphicsElements.h"
#include <string>

class DisplayHint
{
public:
    DisplayHint() = default;
    virtual Size sizeHint(std::string const&s,SizeFactor sizeFactor)const = 0;
    virtual SizeFactor defaultNumberSizeFactor() const = 0;
};

#endif // DISPLAYHINT_H
