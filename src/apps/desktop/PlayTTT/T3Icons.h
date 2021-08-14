#pragma once

#include <QtCore/QMetaType>
#include <QtCore/QMap>
#include <QtCore/QSize>
#include <QtCore/QString>
#include <QtGui/QIcon>
#include <QtGui/QPixmap>


class T3Icons
{
public:
    T3Icons(const QSize &aSize);
    explicit T3Icons() = default;
    T3Icons(const T3Icons &other) = default;
    ~T3Icons() = default;
    T3Icons &operator = (const T3Icons &other) = default;

public:
    QSize iconSize() const { return mIconSize; }
    QIcon icon(const QString &aKey) { return mKeyIconMap.value(aKey); }
    QPixmap pixmap(const QString &aKey);

public:
    void setIconSize(const QSize aSize) { mIconSize = aSize; }

    void setup();

private:
    void setupEmpty(const QString &aKey);

private:
    QSize mIconSize=QSize(32, 32);
    QMap<QString, QIcon> mKeyIconMap;

};

Q_DECLARE_METATYPE(T3Icons);
