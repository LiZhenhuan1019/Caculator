#ifndef QTDISPALYHINT_H
#define QTDISPALYHINT_H
#include "displayhint.h"
#include <QApplication>
#include <QFont>

class QtDisplayHint : public DisplayHint
{
public:
    QtDisplayHint() = default;

    virtual Size sizeHint(const std::string &s, SizeFactor sizeFactor) const override;
    virtual SizeFactor defaultNumberSizeFactor() const override;
//private:
    QFont myfont = QApplication::font();
};

#endif // QTDISPALYHINT_H
