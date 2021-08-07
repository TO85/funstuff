#include "IconFactory.h"



QPixmap IconFactory::solidPixmap(const QColor &aColor, const QSize aSize)
{
    QPixmap result(aSize);
    result.fill(aColor);
    return result;
}

QIcon IconFactory::icon(const QPixmap &aPixmap)
{
    QIcon result(aPixmap);
    return result;
}
