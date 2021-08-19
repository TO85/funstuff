#include "TttPixmaps.h"

#include <QtDebug>
#include <QtGui/QPainter>

TttPixmaps::TttPixmaps(const QSize aSize)
    : cmBaseSize(aSize.isEmpty() ? QSize(48, 48) : aSize)
{
}

QPixmap TttPixmaps::pixmap(const Key aKey, const QSize aSize) const
{
    Q_UNUSED(aSize); // NEEDO(aSize)
    if ( ! contains(aKey)) qWarning() << Q_FUNC_INFO << aKey << "Not Found";
    return value(aKey);
}

QPixmap TttPixmaps::pixmap(const int aKeyStack, const QSize aSize) const
{
    QPixmap result(cmBaseSize);
    result.fill(Qt::magenta);
    if (false)                          {;}
    else if (BackBase   & aKeyStack)    result = result + pixmap(BackBase, aSize);
    else if (EmptyBase  & aKeyStack)    result = result + pixmap(EmptyBase, aSize);
    else if (ClearBase  & aKeyStack)    result = result + pixmap(ClearBase, aSize);
    else if (Circle     & aKeyStack)    result = result + pixmap(Circle, aSize);
    else if (Cross      & aKeyStack)    result = result + pixmap(Cross, aSize);
    else if (LineNS     & aKeyStack)    result = result + pixmap(LineNS, aSize);
    else if (LineEW     & aKeyStack)    result = result + pixmap(LineEW, aSize);
    else if (LineNWSE   & aKeyStack)    result = result + pixmap(LineNWSE, aSize);
    else if (LineNESW   & aKeyStack)    result = result + pixmap(LineNESW, aSize);
    else                                {;}
    if ( ! aSize.isEmpty()) result = result.scaled(aSize);
    return result;
}

void TttPixmaps::setup()
{
    setupBases();
    setupShapes();
    setupLines();
}

void TttPixmaps::setupBases()
{
    QPixmap tBackPxm(cmBaseSize);
    QPixmap tEmptyPxm(cmBaseSize);
    QPixmap tClearPxm(cmBaseSize);
    tBackPxm.fill(cmBackColor);
    tEmptyPxm.fill(cmEmptyColor);
    tClearPxm.fill(cmClearColor);
    insert(BackBase, tBackPxm);
    insert(EmptyBase, tEmptyPxm);
    insert(ClearBase, tClearPxm);
}

void TttPixmaps::setupShapes()
{
    insert(Circle, drawShape(Circle));
    insert(Cross, drawShape(Cross));
}

void TttPixmaps::setupLines()
{
    insert(LineNS, drawLine(LineNS));
    insert(LineEW, drawLine(LineEW));
    insert(LineNWSE, drawLine(LineNWSE));
    insert(LineNESW, drawLine(LineNESW));
}

QPixmap TttPixmaps::drawShape(const Key aKey)
{
    QPixmap result(cmBaseSize);
    result.fill(Qt::transparent);
    const QRect cBaseRect(QPoint(0, 0), cmBaseSize);
    const QRect cShapeRect(cBaseRect.left()   + cmShapeMargin,
                           cBaseRect.top()    + cmShapeMargin,
                           cBaseRect.right()  - cmShapeMargin,
                           cBaseRect.bottom() - cmShapeMargin);
    QPen tPen;
    switch (aKey)
    {
    case Circle:    tPen = QPen(cmCircleColor, cmShapeStrokeWidth);     break;
    case Cross:     tPen = QPen(cmCrossColor,  cmShapeStrokeWidth);     break;
    default:        qWarning() << "Shape key not handled:" << aKey;     break;
    }

    QPainter tPainter(&result);
    tPainter.fillRect(cBaseRect, cmClearColor);
    tPainter.setPen(tPen);
    switch (aKey)
    {
    case Circle:    tPainter.drawEllipse(cShapeRect);                                   break;
    case Cross:     tPainter.drawLine(cShapeRect.topLeft(), cShapeRect.bottomRight());
                    tPainter.drawLine(cShapeRect.topRight(), cShapeRect.bottomLeft());  break;
    default:        qWarning() << "Shape key not handled2:" << aKey;                    break;
    }
    tPainter.end();

    return result;
}

QPixmap TttPixmaps::drawLine(const Key aKey)
{
    QPixmap result(cmBaseSize);
    result.fill(Qt::transparent);
    const QRect cBaseRect(QPoint(0, 0), cmBaseSize);
    const QRect cLineRect(cBaseRect.left()   + cmLineMargin,
                          cBaseRect.top()    + cmLineMargin,
                          cBaseRect.right()  - cmLineMargin,
                          cBaseRect.bottom() - cmLineMargin);
    const QPen cPen(cmLineColor, cmLineStrokeWidth);

    QPainter tPainter(&result);
    tPainter.fillRect(cBaseRect, cmClearColor);
    tPainter.setPen(cPen);
    switch (aKey)
    {
    case LineNS:    tPainter.drawLine(QPoint(cLineRect.center().x(), cLineRect.top()),
                                      QPoint(cLineRect.center().x(), cLineRect.bottom()));  break;
    case LineEW:    tPainter.drawLine(QPoint(cLineRect.left(), cLineRect.center().y()),
                                      QPoint(cLineRect.left(), cLineRect.center().y()));    break;
    case LineNESW:  tPainter.drawLine(cLineRect.topLeft(), cLineRect.bottomRight());        break;
    case LineNWSE:  tPainter.drawLine(cLineRect.topRight(), cLineRect.bottomLeft());        break;
    default:        qWarning() << "Line key not handled2:" << aKey;                         break;
    }
    tPainter.end();

    return result;
}

QPixmap operator + (const QPixmap &lhs, const QPixmap &rhs)
{
    QPixmap result(lhs);
    qDebug() << Q_FUNC_INFO << lhs << rhs << result;
    QPainter tPainter(&result);
//    tPainter.drawPixmap(lhs.rect(), lhs, lhs.rect());
    tPainter.drawPixmap(lhs.rect(), rhs, rhs.rect());
    tPainter.end();
    qDebug() << Q_FUNC_INFO << lhs << rhs << result;
    return result;
}
