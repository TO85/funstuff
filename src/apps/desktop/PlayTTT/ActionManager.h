#pragma once

#include <QObject>

#include <QtCore/QMap>
#include <QtCore/QString>
class QAction;

class ActionManager : public QObject
{
    Q_OBJECT
public:
    typedef QString Key;

public:
    explicit ActionManager(QObject *parent = nullptr);

public:
    bool contains(const Key &aKey) const;

public:
    QAction *addAction(const QString &aText) { return addAction(aText, aText); }
    QAction *addAction(const Key &aKey, const QString &aText);
    QAction *addAction(const Key &aKey, const QIcon &aIcon, const QString &aText);
    QAction *action(const Key &aKey);
    QAction *operator [] (const Key &aKey) { return action(aKey); }
    void setVisible(const Key &aKey, const bool &aVisible=true);
    void setInvisible(const Key &aKey) { setVisible(aKey, false); }

signals:
    void actionAdded(const Key &aKey, QAction *pAction);

private:
    QMap<Key, QAction *> mKeyActionMap;

};

