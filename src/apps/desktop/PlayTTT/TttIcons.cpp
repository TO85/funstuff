#include "TttIcons.h"


TttIcons::TttIcons(const QSize &aSize)
    : mIconSize(aSize.isEmpty() ? QSize(64, 64) : aSize)
{

}

void TttIcons::setup()
{
    setupBack("Back");
    setupEmpty("Empty");
}

QPixmap TttIcons::create(const QColor &aSolidColor, QSize aSize)
{
    if (aSize.isEmpty()) aSize = iconSize();
    QPixmap result(aSize);
    result.fill(aSolidColor);
    return result;
}

void TttIcons::addIcon(const QString &aKey, const QIcon &aIcon)
{
    mKeyIconMap.insert(aKey, aIcon);
}

void TttIcons::setupBack(const QString &aKey)
{
    QIcon tIcon(create(cmBackColor));
    addIcon(aKey, tIcon);
}

void TttIcons::setupEmpty(const QString &aKey)
{
    QIcon tIcon(create(cmEmptyColor));
    addIcon(aKey, tIcon);
}
