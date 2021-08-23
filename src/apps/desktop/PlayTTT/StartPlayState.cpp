#include "StartPlayState.h"

#include <QtDebug>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

#include "ActionManager.h"
#include "MainWindow.h"
#include "TttMachine.h"

StartPlayState::StartPlayState(MainWindow *pMainWindow)
    : mpMainWindow(pMainWindow)
{
    setProperty("StateEnum", TttMachine::StartPlay);
    setProperty("StateName", "StartPlay");
    setObjectName("TttMachine:StartPlay");
    qDebug() << Q_FUNC_INFO << mpMainWindow->objectName() << objectName();
}

void StartPlayState::setup()
{
    qDebug() << Q_FUNC_INFO;
//  TODO?
}

void StartPlayState::onEntry(QEvent *event)
{
    Q_UNUSED(event);
    mainWindow()->actions()->setVisible("StartPlay");
}

void StartPlayState::onExit(QEvent *event)
{
    Q_UNUSED(event);
    mainWindow()->actions()->setInvisible("StartPlay");
}
