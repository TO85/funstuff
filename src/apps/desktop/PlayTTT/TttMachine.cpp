#include "TttMachine.h"

#include "MainWindow.h"

TttMachine::TttMachine(QObject *parent) : QStateMachine(parent)
{
    qDebug() << Q_FUNC_INFO;
    setObjectName("TttMachine");
}

void TttMachine::setup(MainWindow *pMainWindow)
{
    qDebug() << Q_FUNC_INFO;
    void(newState(Construct, "Construct"));
    void(newState(Setup, "Setup"));
    void(newState(StartPlay, "StartPlay"));
    void(newState(StartGame, "StartGame"));
    void(newState(NextPlay, "NextPlay"));
    void(newState(HomePlays, "HomePlays"));
    void(newState(VisitorPlays, "VisitorPlays"));
    void(newState(ShowPlay, "ShowPlay"));
    void(newState(IsWinner, "IsWinner"));
    void(newState(UpdateScore, "UpdateScore"));
    void(newState(Exit, "Exit"));

    void(newTransition(Construct,       Setup));
    void(newTransition(Setup,           StartPlay));
    void(newTransition(StartGame,       NextPlay));
    void(newTransition(HomePlays,       ShowPlay));
    void(newTransition(VisitorPlays,    ShowPlay));
    void(newTransition(ShowPlay,        IsWinner));
    void(newTransition(IsWinner,        UpdateScore));
    void(newTransition(UpdateScore,     StartGame));


    void(newSignalTransition(pMainWindow, StartPlay, SLOT(readyStartPlay), StartGame));

//    void(newSignalTransition(Setup,         SIGNAL(signalSetup()),              StartPlay));
//    void(newSignalTransition(NextPlay,      SIGNAL(signalNextPlayHome()),       HomePlays));
//    void(newSignalTransition(NextPlay,      SIGNAL(signalNextPlayVisitor()),    VisitorPlays));
}

void TttMachine::start() // virtual
{
    qDebug() << Q_FUNC_INFO;
    setInitialState(state(Construct));
    QStateMachine::start();
}

QState *TttMachine::state(const State &aStateEnum)
{
//    qDebug() << Q_FUNC_INFO << aStateEnum << mStateNameMap[aStateEnum];
    Q_ASSERT(mStateMap[aStateEnum]);
    return mStateMap[aStateEnum];
}

QState *TttMachine::newState(const State &aStateEnum, const QString &aName)
{
    QState *pState = new QState(this);
    pState->setProperty("StateEnum", aStateEnum);
    pState->setProperty("StateName", aName);
    pState->setObjectName("TttMachine:"+aName);
    mStateMap.insert(aStateEnum, pState);
    mNameStateMap.insert(aName, aStateEnum);
    mStateNameMap.insert(aStateEnum, aName);
    return pState;
}

QAbstractTransition *TttMachine::newTransition(const State aSender, const State aTarget)
{
    QAbstractTransition *result=nullptr;
    QState *pSender = mStateMap[aSender];
    QState *pTarget = mStateMap[aTarget];
    result = pSender->addTransition(pTarget);
    return result;
}

QSignalTransition *TttMachine::newSignalTransition(QObject *pSender,
                                                   const State aSource,
                                                   const char *pSignal,
                                                   const State aTarget)
{
    QSignalTransition *result=nullptr;
    QState *pTarget = mStateMap[aTarget];
    result = new QSignalTransition(pSender, pSignal);
    result->setTargetState(pTarget);
    mTransitionMap.insert(SenderTarget(aSource, aTarget), result);
    connect(state(aSource), pSignal, state(aTarget), SLOT());
    return result;
}

