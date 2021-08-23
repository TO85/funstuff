#ifndef TTTMACHINE_H
#define TTTMACHINE_H

#include <QtDebug>
#include <QtCore/QObject>
#include <QtCore/QFlags>
#include <QtCore/QPair>
#include <QtCore/QMap>
#include <QtCore/QState>
#include <QtCore/QStateMachine>
#include <QtCore/QString>
#include <QtCore/QSignalTransition>

class MainWindow;

class TttMachine : public QStateMachine
{
    Q_OBJECT
public:
    enum State
    {
        $null           = 0,
        Construct       = 0x00000101,
        Setup           = 0x00000201,
        StartPlay       = 0x00000401,
        StartGame       = 0x00000801,
        NextPlay        = 0x00001001,
        HomePlays       = 0x00002001,
        VisitorPlays    = 0x00004001,
        ShowPlay        = 0x00008001,
        IsWinner        = 0x00010001,
        UpdateScore     = 0x00020001,
        Exit            = 0x00040001,
        $end
    };
    Q_DECLARE_FLAGS(StateFlags, State);
    typedef QPair<State, State> SenderTarget;


public:
    explicit TttMachine(QObject *parent = nullptr);
    QState *state(const State &aStateEnum);

public slots:
    void setup(MainWindow *pMainWindow);
    virtual void start();

signals:

private:
    QState *newState(const State &aStateEnum, const QString &aName);
    QAbstractTransition *newTransition(const State aSender, const State aTarget);
    QSignalTransition *newSignalTransition(QObject *pSender, const State aSource, const char *pSignal, const State aTarget);

private slots:


private:
    QMap<State, QState *> mStateMap;
    QMap<QString, State> mNameStateMap;
    QMap<State, QString> mStateNameMap;

    QMap<SenderTarget, QAbstractTransition *> mTransitionMap;

};

#endif // TTTMACHINE_H
