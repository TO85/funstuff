#include "IconFactory.h"

#include <QtGui/QPainter>


QIcon IconFactory::icon(const QString &aKey)
{
    return mKeyIconMap.value(aKey);
}

QPixmap IconFactory::pixmap(const QString &aKey, const QSize aSize, QIcon::Mode mode, QIcon::State state)
{
    return icon(aKey).pixmap(aSize.isEmpty() ? mIconSize : aSize, mode, state);
}

QPixmap IconFactory::solidPixmap(const QColor &aColor, const QSize aSize) const
{
    QPixmap result(aSize.isEmpty() ? mIconSize : aSize);
    result.fill(aColor);
    return result;
}

void IconFactory::create(const QString &aKey, const Shape aShape, const QColor aColor,
                         const QSize aSize, const QIcon::Mode mode, const QIcon::State state)
{
    const int tStrokeWidth = 5;
    const QSize tSize = aSize.isEmpty() ? mIconSize : aSize;

    QPixmap tPixmap(tSize);
    QPainter tPainter;
    tPainter.begin(&tPixmap);
    QBrush tBackBrush(mBackColor);
    tPainter.setBrush(tBackBrush);
    tPainter.drawRect(QRect(QPoint(0, 0), tSize));
    QPen tStrokePen(QBrush(aColor), tStrokeWidth);
    tPainter.setPen(tStrokePen);
    switch (aShape)
    {
    case Empty:
        // nothing but background
        break;

    case Ex:
        tPainter.drawLine(3, 3, tSize.width() - 3, tSize.height() - 3);
        tPainter.drawLine(tSize.width() - 3, 3, 3, tSize.height() - 3);
        break;

    case Oh:
        tPainter.drawEllipse(3, 3, tSize.width() - 3, tSize.height() - 3);
        break;

    default:
        break;
    }
    tPainter.end();

    addPixmap(aKey, tPixmap, mode, state);
}

void IconFactory::addPixmap(const QString &aKey, const QPixmap &aPixmap,
                           const QIcon::Mode mode, const QIcon::State state)
{
    mKeyIconMap[aKey].addPixmap(aPixmap, mode, state);
}
