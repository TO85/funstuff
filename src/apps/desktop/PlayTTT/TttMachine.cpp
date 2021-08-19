#include "TttMachine.h"

TttMachine::TttMachine(QObject *parent) : QStateMachine(parent)
{
    qDebug() << Q_FUNC_INFO;
    setObjectName("TttMachine");
}

void TttMachine::setup()
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

    void(newSignalTransition(Construct,     SIGNAL(signalConstruct()),          Setup));
//    void(newSignalTransition(Setup,         SIGNAL(signalSetup()),              StartPlay));
    void(newSignalTransition(StartPlay,     SIGNAL(signalStartPlay()),          StartGame));
    void(newSignalTransition(StartGame,     SIGNAL(signalStartGame()),          NextPlay));
//    void(newSignalTransition(NextPlay,      SIGNAL(signalNextPlayHome()),       HomePlays));
  //  void(newSignalTransition(NextPlay,      SIGNAL(signalNextPlayVisitor()),    VisitorPlays));
    void(newSignalTransition(NextPlay,      SIGNAL(signalNextPlayExit()),       Exit));
    void(newSignalTransition(HomePlays,     SIGNAL(signalHomePlays()),          ShowPlay));
    void(newSignalTransition(VisitorPlays,  SIGNAL(signalVisitorPlays()),       ShowPlay));
    void(newSignalTransition(ShowPlay,      SIGNAL(signalShowPlay()),           IsWinner));
    void(newSignalTransition(IsWinner,      SIGNAL(signalIsWinner()),           UpdateScore));
    void(newSignalTransition(UpdateScore,   SIGNAL(signalUpdateScore()),        StartGame));

}

void TttMachine::start() // virtual
{
    qDebug() << Q_FUNC_INFO;
//    qDebug() << state(Construct)->objectName();
  //  qDebug() << state(Construct)->property("StateName");
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

QAbstractTransition *TttMachine::newSignalTransition(const State aSender, const char *pSignal, const State aTarget)
{
    QAbstractTransition *result=nullptr;
    QState *pSender = mStateMap[aSender];
    QState *pTarget = mStateMap[aTarget];
#if 1
    Q_UNUSED(pSignal);  // TODO?
    result = pSender->addTransition(pTarget);
#else
    pSigXn = new QSignalTransition();
    pSigXn->setSenderObject(pSender);
    pSigXn->setTargetState(pTarget);
    pSigXn->setSignal(pSignal);
    mTransitionMap.insert(SenderTarget(aSender, aTarget), pSigXn);
    connect(state(aSender), pSignal, state(aTarget), SLOT());
#endif
    return result;
}

