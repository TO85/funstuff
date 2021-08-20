#include "PlayTttApplication.h"

#include <QtDebug>
#include <QtCore/QTimer>

#include "MainWindow.h"
#include "TttBoardWidget.h"
#include "TttMachine.h"

PlayTttApplication::PlayTttApplication(int &argc, char **argv)
    : QApplication(argc, argv)
    , mpMachine(new TttMachine(this))
{
    qDebug() << Q_FUNC_INFO << arguments();
    setObjectName("PlayT3Application");
}

TttBoardWidget *PlayTttApplication::board()
{
    return mainWindow()->board();
}

PlayTttApplication::IndexVector PlayTttApplication::availableIndicies()
{
    qDebug() << Q_FUNC_INFO;
    Q_ASSERT(mCurrentTokens.count() == board()->gridEntries());
    IndexVector result(board()->gridEntries());
    for (int ix = 0; ix < board()->gridEntries(); ++ix)
        if (mCurrentTokens[ix] == cmEmptyToken)
            result.append(ix);
    return result;
}

void PlayTttApplication::start(MainWindow * pMainWindow)
{
    qDebug() << Q_FUNC_INFO << pMainWindow->objectName();
    mpMainWindow = pMainWindow;
    QTimer::singleShot(500, this, &PlayTttApplication::startMachine);
}

void PlayTttApplication::startMachine()
{
    qDebug() << Q_FUNC_INFO;
    machine()->setup();
    setupConnections();
    machine()->start();
}

void PlayTttApplication::startPlay()
{
    qDebug() << Q_FUNC_INFO;
    // NEEDO: it
}

void PlayTttApplication::setupConnections()
{
    qDebug() << Q_FUNC_INFO;
    connect(mainWindow(), &MainWindow::setupComplete, this, &PlayTttApplication::startPlay);
    connect(machine()->state(TttMachine::Construct),       SIGNAL(entered()), this, SLOT(enterConstruct()));
    connect(machine()->state(TttMachine::Setup),           SIGNAL(entered()), this, SLOT(enterSetup()));
    connect(machine()->state(TttMachine::StartPlay),       SIGNAL(entered()), this, SLOT(enterStartPlay()));
    connect(machine()->state(TttMachine::StartGame),       SIGNAL(entered()), this, SLOT(enterStartGame()));
    connect(machine()->state(TttMachine::NextPlay),        SIGNAL(entered()), this, SLOT(enterNextPlay()));
    connect(machine()->state(TttMachine::HomePlays),       SIGNAL(entered()), this, SLOT(enterHomePlays()));
    connect(machine()->state(TttMachine::VisitorPlays),    SIGNAL(entered()), this, SLOT(enterVisitorPlays()));
    connect(machine()->state(TttMachine::ShowPlay),        SIGNAL(entered()), this, SLOT(enterShowPlay()));
    connect(machine()->state(TttMachine::IsWinner),        SIGNAL(entered()), this, SLOT(enterIsWinner()));
    connect(machine()->state(TttMachine::UpdateScore),     SIGNAL(entered()), this, SLOT(enterUpdateScore()));
    connect(machine()->state(TttMachine::Exit),            SIGNAL(entered()), this, SLOT(enterExit()));
    connect(machine(), SIGNAL(runningChanged(bool)), this, SLOT(machineRunning(bool)));
}

void PlayTttApplication::enterConstruct()
{
    qDebug() << Q_FUNC_INFO;
    mainWindow()->construct();
    emit signalConstruct();
}

void PlayTttApplication::enterSetup()
{
    qDebug() << Q_FUNC_INFO;
    mainWindow()->setup();
    emit signalSetup();
}

void PlayTttApplication::enterStartPlay()
{
    qDebug() << Q_FUNC_INFO;
    mNextFirstPlayer = random().takeBit();
    emit signalStartPlay();
}

void PlayTttApplication::enterStartGame()
{
    qDebug() << Q_FUNC_INFO;
    mNextFirstPlayer ^= true;
    mCurrentPlayer = mNextFirstPlayer;
    emit signalStartGame();
}

void PlayTttApplication::enterNextPlay()
{
    qDebug() << Q_FUNC_INFO;

}

void PlayTttApplication::enterExit()
{
    qDebug() << Q_FUNC_INFO;
    QTimer::singleShot(100, qApp, SLOT(quit()));
}

void PlayTttApplication::machineRunning(const bool running)
{
    qDebug() << Q_FUNC_INFO;
    qDebug(running ? "starting" : "stopping");

}


