#pragma once

#include <QtDebug>
#include <QtWidgets/QApplication>
#include <QtWidgets/QWidget>

#include "Random.h"
class MainWindow;
class TttMachine;

class PlayTttApplication : public QApplication
{
    Q_OBJECT
public:
    PlayTttApplication(int &argc, char **argv);
    MainWindow *mainWindow() { return mpMainWindow; }
    TttMachine *machine() { return mpMachine; }
    Random random() { return mRandom; }

public:
    bool isHomeCurrent() { return mCurrentPlayer; }
    bool isVistorCurrent() { return ! isHomeCurrent(); }

public slots:
    void start(MainWindow *pMainWindow);
    void startMachine();
    void windowFinished() { mSetupFinished = true; }

private slots:
    void setupConnections();
    void enterConstruct();
    void enterSetup();
    void enterStartPlay();
    void enterStartGame();
    void enterNextPlay();
    void enterNextPlayHome()    { qDebug("enterNextPlayHome()");    emit signalNextPlayHome(); }
    void enterNextPlayVisitor() { qDebug("enterNextPlayVisitor()"); emit signalNextPlayVisitor(); }
    void enterNextPlayExit()    { qDebug("enterNextPlayExit()");    emit signalNextPlayExit(); }
    void enterHomePlays()       { qDebug("enterHomePlays()");       emit signalHomePlays(); }
    void enterVisitorPlays()    { qDebug("enterVisitorPlays()");    emit signalVisitorPlays(); }
    void enterShowPlay()        { qDebug("enterShowPlay()");        emit signalShowPlay(); }
    void enterIsWinner()        { qDebug("enterIsWinner()");        emit signalIsWinner(); }
    void enterUpdateScore()     { qDebug("enterUpdateScore()");     emit signalUpdateScore(); }
    void enterExit();
    void machineRunning(const bool running);

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
    MainWindow *mpMainWindow=nullptr;
    TttMachine *mpMachine=nullptr;
    Random mRandom;
    bool mSetupFinished=false;
    bool mNextFirstPlayer=false;
    bool mCurrentPlayer=false;
};
