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
