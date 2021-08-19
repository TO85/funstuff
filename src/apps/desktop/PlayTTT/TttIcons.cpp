#include "TttIcons.h"

#include <QtDebug>
#include <QtGui/QPainter>
#include <QtGui/QPen>
#include <QtCore/QRect>

TttIcons::TttIcons(const QSize &aSize)
    : mIconSize(aSize.isEmpty() ? iconSize() : aSize)
{
    qDebug() << Q_FUNC_INFO << aSize;
}

QPixmap TttIcons::pixmap(const QString &aKey, QIcon::Mode aMode, QIcon::State aState) const
{
    qDebug() << Q_FUNC_INFO << aKey << aMode << aState;
    return pixmap(iconSize(), aKey, aMode, aState);
}

QPixmap TttIcons::pixmap(const QSize &aSize, const QString &aKey, QIcon::Mode aMode, QIcon::State aState) const
{
    qDebug() << Q_FUNC_INFO << aSize << aKey << aMode << aState;
    return icon(aKey).pixmap(aSize, aMode, aState);
}

void TttIcons::setup()
{
    qDebug() << Q_FUNC_INFO;
    setupBack("BackBase");
    setupEmpty("EmptyBase");
    setupClear("ClearBase");
    setupCircle("Circle");
    setupCross("Cross");
    addIcon("CrossLayer", createLayer("Cross"));
}

QPixmap TttIcons::createColor(const QColor &aSolidColor, QSize aSize)
{
    qDebug() << Q_FUNC_INFO << aSolidColor << aSize;
    if (aSize.isEmpty()) aSize = iconSize();
    QPixmap result(aSize);
    result.fill(aSolidColor);
    return result;
}

QPixmap TttIcons::createLayer(const QString &aKey, QSize aSize)
{
    qDebug() << Q_FUNC_INFO << aKey << aSize;
    if (aSize.isEmpty()) aSize = iconSize();
    QPixmap result(aSize);
    QPainter * pPainter = new QPainter(&result);
    pPainter->drawPixmap(QRect(QPoint(0, 0), aSize), icon("Clear").pixmap(aSize));
    if (false) ;
    else if ("Circle"    == aKey)       drawShape(pPainter, Circle,    aSize);
    else if ("Cross"     == aKey)       drawShape(pPainter, Cross,     aSize);
    else if ("LineCross" == aKey)       drawShape(pPainter, LineCross, aSize);
    else if ("LineNS" == aKey)          drawShape(pPainter, LineNS,    aSize);
    else if ("LineEW" == aKey)          drawShape(pPainter, LineEW,    aSize);
    else if ("LineNWSE" == aKey)        drawShape(pPainter, LineNWSE,  aSize);
    else if ("LineNESW" == aKey)        drawShape(pPainter, LineNESW,  aSize);
    else qDebug() << Q_FUNC_INFO << "Unhandled Shape" << aKey;
    pPainter->end();
    return result;
}

void TttIcons::drawShape(QPainter *pPainter, const Shape aShape, const QSize aSize)
{
    qDebug() << Q_FUNC_INFO << aShape << aSize;

    const QRect cRect(QPoint(0, 0), aSize);
    const QRect cShapeRect(QPoint(cmShapeMargin, cmShapeMargin),
                           QPoint(cRect.height() - cmShapeMargin,
                                  cRect.width()  - cmShapeMargin));
    const QRect cLineRect( QPoint(cmLineMargin,  cmLineMargin),
                           QPoint(cRect.height() - cmLineMargin,
                                  cRect.width()  - cmLineMargin));
    const QPoint cLineTopCenter(   (cLineRect.left() + cLineRect.right()) / 2, cLineRect.top());
    const QPoint cLineBottomCenter((cLineRect.left() + cLineRect.right()) / 2, cLineRect.bottom());
    const QPoint cLineLeftCenter(   cLineRect.left(), (cLineRect.top() + cLineRect.bottom()) / 2);
    const QPoint cLineRightCenter(  cLineRect.right(),(cLineRect.top() + cLineRect.bottom()) / 2);
    switch (aShape)
    {
    case Circle:    pPainter->setPen(QPen(cmCircleColor, cmShapeStrokeWidth));      break;
    case Cross:     pPainter->setPen(QPen(cmCrossColor, cmShapeStrokeWidth));       break;
    case LineCross:
    case LineNS:
    case LineEW:
    case LineNWSE:
    case LineNESW:  pPainter->setPen(QPen(cmLineColor, cmLineStrokeWidth));         break;
    default:        qDebug() << Q_FUNC_INFO << "Unhandled Shape" << aShape;         break;
    }

    switch (aShape)
    {
    case Circle:    pPainter->drawEllipse(cShapeRect);                                          break;
    case Cross:     pPainter->drawLine(QLine(cShapeRect.topLeft(), cShapeRect.bottomRight()));
                    pPainter->drawLine(QLine(cShapeRect.topRight(), cShapeRect.bottomLeft()));  break;
    case LineCross: pPainter->drawLine(QLine(cLineRect.topLeft(), cLineRect.bottomRight()));
                    pPainter->drawLine(QLine(cLineRect.topRight(), cLineRect.bottomLeft()));    break;
    case LineNS:    pPainter->drawLine(QLine(cLineTopCenter, cLineBottomCenter));               break;
    case LineEW:    pPainter->drawLine(QLine(cLineTopCenter, cLineBottomCenter));               break;
    case LineNWSE:  pPainter->drawLine(QLine(cLineRect.topLeft(), cLineRect.bottomRight()));    break;
    case LineNESW:  pPainter->drawLine(QLine(cLineRect.topRight(), cLineRect.bottomLeft()));    break;
    default:        qDebug() << Q_FUNC_INFO << "Unhandled Shape again" << aShape;               break;
    }
}

void TttIcons::addIcon(const QString &aKey, const QIcon &aIcon)
{
    qDebug() << Q_FUNC_INFO << aKey << aIcon;
    mKeyIconMap.insert(aKey, aIcon);
}

void TttIcons::setupBack(const QString &aKey)
{
    qDebug() << Q_FUNC_INFO << aKey;
    QIcon tIcon(createColor(cmBackColor));
    addIcon(aKey, tIcon);
}

void TttIcons::setupEmpty(const QString &aKey)
{
    qDebug() << Q_FUNC_INFO << aKey;
    QIcon tIcon(createColor(cmEmptyColor));
    addIcon(aKey, tIcon);
}

void TttIcons::setupClear(const QString &aKey)
{
    qDebug() << Q_FUNC_INFO << aKey;
//    QIcon tIcon(createColor(cmClearColor));
    QPixmap tClearPxm = createColor(cmClearColor, iconSize());
    QIcon tIcon;
    tIcon.addPixmap(tClearPxm, QIcon::Normal, QIcon::Off);
    tIcon.addPixmap(tClearPxm, QIcon::Normal, QIcon::On);
    qDebug() << tIcon;
    addIcon(aKey, tIcon);
}

void TttIcons::setupCircle(const QString &aKey)
{
    qDebug() << Q_FUNC_INFO << aKey;
    QPixmap tBase = pixmap("Clear");
    QPixmap tCircle = pixmap("CircleLayer");
    QPainter tPainter(&tBase);
    tPainter.drawPixmap(tCircle.rect(), tCircle, tBase.rect());
    tPainter.end();
    QIcon tIcon(tBase);
    addIcon(aKey, tIcon);
}

void TttIcons::setupCross(const QString &aKey)
{
    qDebug() << Q_FUNC_INFO << aKey;
    QPixmap tBase = pixmap("ClearBase");
    QPixmap tCross = pixmap("CrossLayer");
    QPainter tPainter(&tBase);
    tPainter.drawPixmap(tCross.rect(), tCross, tBase.rect());
    tPainter.end();
    QIcon tIcon(tBase);
    addIcon(aKey, tIcon);
}
