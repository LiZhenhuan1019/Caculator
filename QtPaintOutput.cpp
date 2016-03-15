#include "caculatorheader.h"
#include "QtPaintOutput.h"
#include <QPainter>
#include "QtGraphicsConvert.h"
void QtPaintOutput::put(const std::string &s, Rect const&r, SizeFactor sizefactor)
{
    QFont oldFont = pPainter->font();
    QFont newFont = oldFont;
    newFont.setPointSize(sizefactor);
    pPainter->setFont(newFont);
    pPainter->drawText(toRectF(r),
                       Qt::AlignVCenter|Qt::AlignHCenter,QString(s.c_str()));
    pPainter->setFont(oldFont);

}

