#include "TttIcons.h"


TttIcons::TttIcons(const QSize &aSize)
    : mIconSize(aSize.isEmpty() ? QSize(64, 64) : aSize)
{

}

void TttIcons::setup()
{
    setupEmpty("Empty");
}

void TttIcons::setupEmpty(const QString &aKey)
{
}
