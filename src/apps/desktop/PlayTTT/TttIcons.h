#pragma once

#include <QtDebug>
#include <QtGlobal>
#include <QtCore/QMetaType>
#include <QtCore/QMap>
#include <QtCore/QSize>
#include <QtCore/QString>
#include <QtGui/QColor>
#include <QtGui/QIcon>
#include <QtGui/QPixmap>

class TttIcons
{
public:
    enum Shape
    {
        Empty = 0,
        Cross,
        Circle,
        $maximum
    };

public:
    TttIcons(const QSize &aSize);
    explicit TttIcons() = default;
    TttIcons(const TttIcons &other) = default;
    ~TttIcons() = default;
    TttIcons &operator = (const TttIcons &other) = default;

public:
    QSize iconSize() const { return mIconSize; }
    QIcon icon(const QString &aKey) const { return mKeyIconMap.value(aKey); }

public:
    void setup();
    void setIconSize(const QSize aSize) { mIconSize = aSize; }


private:
    QPixmap create(const QColor &aSolidColor, QSize aSize=QSize());

    void addIcon(const QString &aKey, const QIcon &aIcon);

    void setupBack(const QString &aKey);
    void setupEmpty(const QString &aKey);

private:
    const QColor cmBackColor=QColor(Qt::lightGray);
    const QColor cmEmptyColor=QColor(Qt::white);
    QSize mIconSize=QSize(64, 64);
    QMap<QString, QIcon> mKeyIconMap;

};

Q_DECLARE_METATYPE(TttIcons);
