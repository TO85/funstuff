#pragma once

#include <QtCore/QMetaType>
#include <QtCore/QMap>
#include <QtCore/QSize>
#include <QtCore/QString>
#include <QtGui/QIcon>
#include <QtGui/QPixmap>

class IconFactory
{
public:
    explicit IconFactory() = default;
    IconFactory(const IconFactory &other) = default;
    ~IconFactory() = default;
    IconFactory &operator = (const IconFactory &other) = default;

public:
    QIcon icon(const QString &aKey, const QSize aSize);
    QPixmap pixmap(const QString &aKey, const QSize aSize);

public:
    void addFile(const QString &aKey, const QPixmap &aPixmap,
                 const QSize &size = QSize(), QIcon::Mode mode = QIcon::Normal, QIcon::State state = QIcon::Off);
    void addPixmap(const QString &aKey, const QPixmap &aPixmap,
                   const QSize &size = QSize(), QIcon::Mode mode = QIcon::Normal, QIcon::State state = QIcon::Off);

public:
    static QPixmap solidPixmap(const QColor &aColor, const QSize aSize=QSize(64, 64));
    static QIcon icon(const QPixmap &aPixmap);

private:
    QMap<QString, QIcon> mKeyIconMap;
};


Q_DECLARE_METATYPE(IconFactory);
