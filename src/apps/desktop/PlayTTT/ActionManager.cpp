#include "ActionManager.h"

#include <QtDebug>
#include <QtWidgets/QAction>

ActionManager::ActionManager(QObject *parent)
    : QObject(parent)
{
    setObjectName("ActionManager");
    qDebug() << Q_FUNC_INFO << objectName() << (parent ? parent->objectName() : "Orphan");
}

bool ActionManager::contains(const Key &aKey) const
{
    return mKeyActionMap.contains(aKey);
}

void ActionManager::addAction(QAction *pAction)
{
    qDebug() << Q_FUNC_INFO << pAction->text();
    mKeyActionMap.insert(pAction->text(), pAction);
    mActionKeyMap.insert(pAction, pAction->text());
}

void ActionManager::addAction(const Key &aKey, QAction *pAction)
{
    qDebug() << Q_FUNC_INFO << aKey;
    mKeyActionMap.insert(aKey, pAction);
    mActionKeyMap.insert(pAction, aKey);
}

QAction *ActionManager::action(const Key &aKey)
{
    qDebug() << Q_FUNC_INFO << aKey;
    if ( ! contains(aKey)) qWarning() << Q_FUNC_INFO << "not contains:" << aKey;
    return mKeyActionMap.value(aKey);
}

void ActionManager::setVisible(const Key &aKey, const bool &aVisible)
{
    action(aKey)->setVisible(aVisible);
}
