#ifndef QTPAINTOUTPUT_H
#define QTPAINTOUTPUT_H
#include "OutputBase.h"
class QPainter;
class QtPaintOutput : public OutputBase
{
public:
    QtPaintOutput() = default;
    QtPaintOutput(QPainter *p):pPainter(p)
    {}
    virtual void put(const std::string& s, Rect const&r, SizeFactor sizefactor) override;
private:
    QPainter *pPainter = nullptr;
};

#endif // QTPAINTOUTPUT_H
