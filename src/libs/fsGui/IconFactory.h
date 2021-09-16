#pragma once

#include <QtGlobal>

#include <QtCore/QMap>
#include <QtCore/QSettings>
#include <QtGui/QIcon>
#include <QtGui/QPicture>

class QPixmap;
class QSize;

class IconFactory
{
public:
    typedef QString Key; // TODO: MultiName
    typedef QSettings::SettingsMap Config;
    class Painter : protected QPicture
    {
    protected:
        Painter(const Config &aConfig);
        virtual void record(const Config &aConfig) = 0;
        virtual bool play(QPainter * pPainter);
        virtual bool play(QPainter * pPainter, const Config &aConfig);
    };

public:
    IconFactory();

public:
    QIcon icon(const Key &aKey, const QSize aSize, const Config &aConfig=Config());
    QPixmap pixmap(const Key &aKey, const QSize aSize, const Config &aConfig=Config(),
                   const QIcon::Mode aMode=QIcon::Normal,
                   const QIcon::State aState=QIcon::Off);

public:
    void clear();
    void registerPainter(const Key &aKey, Painter *pPainter);

private:
    QMap<Key, QPicture *> mKeyPictureMap;
};

