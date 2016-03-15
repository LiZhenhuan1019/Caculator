#include "QtDisplayHint.h"
#include <QFont>
#include <QFontMetrics>
#include <QApplication>
Size QtDisplayHint::sizeHint(const std::string &s,SizeFactor sizeFactor) const
{
    QFont thisfont = myfont;
    thisfont.setPointSize(sizeFactor);
    QFontMetrics m(thisfont);
    QRect r = m.boundingRect(s.c_str());
    return Size(r.width(),r.height());
}

SizeFactor QtDisplayHint::defaultNumberSizeFactor() const
{
    return 12;
}

