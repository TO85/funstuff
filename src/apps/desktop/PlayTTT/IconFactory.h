#pragma once

#include <QtCore/QFileInfo>
#include <QtCore/QMetaType>
#include <QtCore/QMap>
#include <QtCore/QSize>
#include <QtCore/QString>
#include <QtGui/QIcon>
#include <QtGui/QPicture>
#include <QtGui/QPixmap>

class IconFactory
{
public:
    enum Shape
    {
        Empty = 0,
        Ex,
        Oh,
        $maximum
    };

public:
    explicit IconFactory() = default;
    IconFactory(const IconFactory &other) = default;
    ~IconFactory() = default;
    IconFactory &operator = (const IconFactory &other) = default;

public:
    QIcon icon(const QString &aKey);
    QPixmap pixmap(const QString &aKey, const QSize aSize=QSize(),
                   QIcon::Mode mode = QIcon::Normal, QIcon::State state = QIcon::Off);
    QPixmap solidPixmap(const QColor &aColor, const QSize aSize=QSize()) const;

public:
    void create(const QString &aKey, const Shape aShape, const QColor aColor,
                const QSize aSize=QSize(),
                const QIcon::Mode mode = QIcon::Normal,
                const QIcon::State state = QIcon::Off);
    void setSize(const QSize aSize) { mIconSize = aSize; }
    void addIconFile(const QString &aKey, const QFileInfo &aFileInfo,
                     const QIcon::Mode mode = QIcon::Normal, const QIcon::State state = QIcon::Off);
    void addPixmap(const QString &aKey, const QPixmap &aPixmap,
                   const QIcon::Mode mode = QIcon::Normal, const QIcon::State state = QIcon::Off);
    void addPicture(const QString &aKey, const QPicture &aPicture,
                    const QIcon::Mode mode = QIcon::Normal, const QIcon::State state = QIcon::Off);

private:
    QSize mIconSize;
    QColor mBackColor=Qt::gray;
    QMap<QString, QIcon> mKeyIconMap;
};


Q_DECLARE_METATYPE(IconFactory);
