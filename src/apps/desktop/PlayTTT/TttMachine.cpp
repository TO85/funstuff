#include "TttMachine.h"

TttMachine::TttMachine(QObject *parent) : QStateMachine(parent)
{
    ctor();
}

void TttMachine::ctor()
{
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
    void(newSignalTransition(Setup,         SIGNAL(signalSetup()),              StartPlay));
    void(newSignalTransition(StartPlay,     SIGNAL(signalStartPlay()),          StartGame));
    void(newSignalTransition(StartGame,     SIGNAL(signalStartGame()),          NextPlay));
    void(newSignalTransition(NextPlay,      SIGNAL(signalNextPlayHome()),       HomePlays));
    void(newSignalTransition(NextPlay,      SIGNAL(signalNextPlayVisitor()),    VisitorPlays));
    void(newSignalTransition(NextPlay,      SIGNAL(signalNextPlayExit()),       Exit));
    void(newSignalTransition(HomePlays,     SIGNAL(signalHomePlays()),          ShowPlay));
    void(newSignalTransition(VisitorPlays,  SIGNAL(signalVisitorPlays()),       ShowPlay));
    void(newSignalTransition(ShowPlay,      SIGNAL(signalShowPlay()),           IsWinner));
    void(newSignalTransition(IsWinner,      SIGNAL(signalIsWinner()),           UpdateScore));
    void(newSignalTransition(UpdateScore,   SIGNAL(signalUpdateScore()),        StartGame));
}

QState *TttMachine::newState(const State &aStateEnum, const QString &aName)
{
    QState *pState = new QState(this);
    pState->assignProperty(pState, "StateEnum", aStateEnum);
    pState->assignProperty(pState, "StateName", aName);
    mStateMap.insert(aStateEnum, pState);
    mNameStateMap.insert(aName, aStateEnum);
    mStateNameMap.insert(aStateEnum, aName);
    return pState;
}

QSignalTransition *TttMachine::newSignalTransition(const SenderTarget aSenderTarget, const char *pSignal)
{
    return newSignalTransition(aSenderTarget.first, pSignal, aSenderTarget.second);
}

QSignalTransition *TttMachine::newSignalTransition(const State aSender, const char *pSignal, const State aTarget)
{
    QState *pSender = mStateMap[aSender];
    QState *pTarget = mStateMap[aTarget];
    QSignalTransition *pSigXn = new QSignalTransition();
    pSigXn->setSenderObject(pSender);
    pSigXn->setTargetState(pTarget);
    pSigXn->setTransitionType(QSignalTransition::ExternalTransition);
    pSigXn->setSignal(pSignal);
    mTransitionMap.insert(SenderTarget(aSender, aTarget), pSigXn);
    return pSigXn;
}

