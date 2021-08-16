#pragma once

#include <QtDebug>
#include <QtWidgets/QApplication>
#include <QtWidgets/QWidget>

class MainWindow;
class TttMachine;

class PlayTttApplication : public QApplication
{
    Q_OBJECT
public:
    PlayTttApplication(int &argc, char **argv);
    MainWindow *mainWindow() { return mpMainWindow; }
    TttMachine *machine() { return mpMachine; }

public slots:
    void start(MainWindow *pMainWindow);
    void startMachine();
    void windowFinished() { mSetupFinished = true; }

private slots:
    void setupConnections();
    void enterConstruct();
    void enterSetup();
    void enterWaitSetup();
    void enterStartPlay()       { qDebug("enterStartPlay()");       emit signalStartPlay(); }
    void enterStartGame()       { qDebug("enterStartGame()");       emit signalStartGame(); }
    void enterNextPlay()        { qDebug("enterNextPlay()"); }
    void enterNextPlayHome()    { qDebug("enterNextPlayHome()");    emit signalNextPlayHome(); }
    void enterNextPlayVisitor() { qDebug("enterNextPlayVisitor()"); emit signalNextPlayVisitor(); }
    void enterNextPlayExit()    { qDebug("enterNextPlayExit()");    emit signalNextPlayExit(); }
    void enterHomePlays()       { qDebug("enterHomePlays()");       emit signalHomePlays(); }
    void enterVisitorPlays()    { qDebug("enterVisitorPlays()");    emit signalVisitorPlays(); }
    void enterShowPlay()        { qDebug("enterShowPlay()");        emit signalShowPlay(); }
    void enterIsWinner()        { qDebug("enterIsWinner()");        emit signalIsWinner(); }
    void enterUpdateScore()     { qDebug("enterUpdateScore()");     emit signalUpdateScore(); }
    void enterExit()            { qDebug("enterConstruct()");       emit signalExit(); }
    void machineRunning(const bool running);

signals:
    void signalConstruct();
    void signalSetup();
    void signalWaitSetup();
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
    bool mSetupFinished=false;
};
