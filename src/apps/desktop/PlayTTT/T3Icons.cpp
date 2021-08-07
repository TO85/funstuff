#include "T3Icons.h"


QPixmap T3Icons::pixmap(const QString &aKey)
{
    const QIcon tIcon = icon(aKey);
    return QPixmap();
}

void T3Icons::setup()
{
    setupEmpty("Empty");
}

void T3Icons::setupEmpty(const QString &aKey)
{

}
