#pragma once

#include <QtCore/QFlags>
#include <QtCore/QMap>
#include <QtCore/QSize>
#include <QtCore/QString>
#include <QtGui/QPixmap>

class TttPixmaps : public QMap<int, QPixmap>
{
public:
    enum Key
    {
        $null               = 0,
        BackBase            = 0x00000001,
        EmptyBase           = 0x00000002,
        ClearBase           = 0x00000004,
        $BaseMask           = 0x000000FF,

        Circle              = 0x00000100,
        Cross               = 0x00000200,
        $ShapeMask          = 0x0000FF00,

        LineNS              = 0x00020000,
        LineEW              = 0x00040000,
        LineNWSE            = 0x00080000,
        LineNESW            = 0x00100000,
        $LineMask           = 0x00FF0000,
        $maximum
    };
    Q_DECLARE_FLAGS(Keys, Key);

public:
    TttPixmaps(const QSize aSize=QSize());

public:
    QPixmap pixmap(const Key aKey, const QSize aSize=QSize()) const;
    QPixmap pixmap(const int aKeyStack, const QSize aSize=QSize()) const;

public:
    void setup();

private:
    void setupBases();
    void setupShapes();
    void setupLines();
    QPixmap drawShape(const Key aKey);
    QPixmap drawLine(const Key aKey);

private:
    const QSize cmBaseSize;
    const QColor cmBackColor=QColor(Qt::lightGray);
    const QColor cmEmptyColor=QColor(Qt::white);
    const QColor cmClearColor=QColor(Qt::transparent);
    const QColor cmCircleColor=QColor(Qt::red);
    const QColor cmCrossColor=QColor(Qt::blue);
    const QColor cmLineColor=QColor(Qt::black);
    const int cmShapeStrokeWidth=5;
    const int cmLineStrokeWidth=3;
    const int cmShapeMargin=5;
    const int cmLineMargin=3;
};

extern QPixmap operator + (const QPixmap &lhs, const QPixmap &rhs);

