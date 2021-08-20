#include "TttPixmaps.h"

#include <QtDebug>
#include <QtCore/QDir>
#include <QtCore/QTemporaryFile>
#include <QtGui/QPainter>

TttPixmaps::TttPixmaps(const QSize aSize)
    : cmBaseSize(aSize.isEmpty() ? QSize(48, 48) : aSize)
{
    qDebug() << Q_FUNC_INFO << cmBaseSize;
}

QPixmap TttPixmaps::pixmap(const Key aKey, const QSize aSize) const
{
    qDebug() << Q_FUNC_INFO << aKey << aSize;
    Q_UNUSED(aSize); // NEEDO(aSize)
    QPixmap result;
    if ( ! mKeysPixmapMap.contains(aKey)) qWarning() << Q_FUNC_INFO << aKey << "Not Found";
    result =  mKeysPixmapMap.value(aKey);
    writeTempPixmap("Value", aKey, result);
    return result;
}

QPixmap TttPixmaps::pixmap(const int aKeyStack, const QSize aSize) const
{
    qDebug() << Q_FUNC_INFO << aKeyStack << aSize;
    QPixmap result(cmBaseSize);
    result.fill(Qt::magenta);
    if (false)                          {;}
    else if (BackBase   & aKeyStack)    result = result + pixmap(BackBase);
    else if (EmptyBase  & aKeyStack)    result = result + pixmap(EmptyBase);
    else if (ClearBase  & aKeyStack)    result = result + pixmap(ClearBase);
    else if (Circle     & aKeyStack)    result = result + pixmap(Circle);
    else if (Cross      & aKeyStack)    result = result + pixmap(Cross);
    else if (LineNS     & aKeyStack)    result = result + pixmap(LineNS);
    else if (LineEW     & aKeyStack)    result = result + pixmap(LineEW);
    else if (LineNWSE   & aKeyStack)    result = result + pixmap(LineNWSE);
    else if (LineNESW   & aKeyStack)    result = result + pixmap(LineNESW);
    else                                {;}
    if ( ! aSize.isEmpty()) result = result.scaled(aSize);
    writeTempPixmap("Stack", aKeyStack, result);
    return result;
}

void TttPixmaps::setup()
{
    qDebug() << Q_FUNC_INFO;
    setupBases();
    setupShapes();
    setupLines();
}

void TttPixmaps::insert(const int aKey, const QPixmap &aPixmap)
{
    qDebug() << Q_FUNC_INFO;
    writeTempPixmap("Insert", aKey, aPixmap);
    mKeysPixmapMap.insert(aKey, aPixmap);
}

void TttPixmaps::setupBases()
{
    qDebug() << Q_FUNC_INFO;
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
    qDebug() << Q_FUNC_INFO;
    insert(Circle, drawShape(Circle));
    insert(Cross, drawShape(Cross));
}

void TttPixmaps::setupLines()
{
    qDebug() << Q_FUNC_INFO;
    insert(LineNS, drawLine(LineNS));
    insert(LineEW, drawLine(LineEW));
    insert(LineNWSE, drawLine(LineNWSE));
    insert(LineNESW, drawLine(LineNESW));
}

QPixmap TttPixmaps::drawShape(const Key aKey)
{
    qDebug() << Q_FUNC_INFO << aKey;
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
    qDebug() << Q_FUNC_INFO << aKey;
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

bool TttPixmaps::writeTempPixmap(const QString &aName, const int &aKeys, const QPixmap &aPixmap) const
{
#ifdef QT_DEBUG
    static int tSeq = 0;
    QDir tDir = QDir::current();
    tDir.mkpath("./tmp");
    tDir.cd("./tmp");
    const QString tFileName = QString("%1+0x%2+%3.png").arg(aName)
            .arg(aKeys, 6, 16, QLatin1Char('0')).arg(++tSeq, 3, 10, QLatin1Char('0'));
    QFileInfo tFI(tDir, tFileName);
    bool ok =  aPixmap.save(tFI.absoluteFilePath());
    qDebug() << (ok ? "Wrote to:" : "FAILED:") << tFI.absoluteFilePath()
             << aPixmap.size() << aPixmap.isNull() << Qt::hex << aPixmap.cacheKey() << Qt::dec;
    return ok;
#else
    return true;
#endif
}

QPixmap operator + (const QPixmap &lhs, const QPixmap &rhs)
{
    QPixmap result(lhs);
    QPainter tPainter(&result);
    tPainter.drawPixmap(lhs.rect(), rhs, rhs.rect());
    tPainter.end();
    qDebug() << Q_FUNC_INFO << lhs << rhs << result;
    return result;
}
