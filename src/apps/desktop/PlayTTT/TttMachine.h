#ifndef TTTMACHINE_H
#define TTTMACHINE_H

#include <QtCore/QObject>
#include <QtCore/QPair>
#include <QtCore/QMap>
#include <QtCore/QState>
#include <QtCore/QStateMachine>
#include <QtCore/QString>
#include <QtCore/QSignalTransition>

#include <QtCore/QFlags>

class TttMachine : public QStateMachine
{
    Q_OBJECT
public:
    enum State
    {
        $null           = 0,
        Construct       = 0x00000001,
        Setup           = 0x00000002,
        StartPlay       = 0x00000004,
        StartGame       = 0x00000008,
        NextPlay        = 0x00000010,
        HomePlays       = 0x00000020,
        VisitorPlays    = 0x00000040,
        ShowPlay        = 0x00000080,
        IsWinner        = 0x00000100,
        UpdateScore     = 0x00000200,
        Exit            = 0x00000400,
        $end
    };
    Q_DECLARE_FLAGS(StateFlags, State);
    typedef QPair<State, State> SenderTarget;


public:
    explicit TttMachine(QObject *parent = nullptr);
    void ctor();

signals:
    void signalConstruct();
    void signalSetup();
    void signalStartPlay();
    void signalStartGame();
    void signalNextPlayHome();
    void signalNextPlayVisitor();
    void signalNextPlayExit();
    void signalHomePlays();
    void signalVisitorPlays();
    void signalShowPlay();
    void signalIsWinner();
    void signalUpdateScore();
    void signalExit();

private:
    QState *newState(const State &aStateEnum, const QString &aName);
    QSignalTransition *newSignalTransition(const SenderTarget aSenderTarget,
                                           const char *pSignal);
    QSignalTransition *newSignalTransition(const State aSender,
                                           const char *pSignal,
                                           const State aTarget);

private:
    QMap<State, QState *> mStateMap;
    QMap<QString, State> mNameStateMap;
    QMap<State, QString> mStateNameMap;

    QMap<SenderTarget, QAbstractTransition *> mTransitionMap;

};

#endif // TTTMACHINE_H
