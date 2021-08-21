#pragma once

#include <QtDebug>
#include <QtCore/QChar>
#include <QtWidgets/QApplication>
#include <QtWidgets/QWidget>

#include "Random.h"
class MainWindow;
class TttMachine;
class TttBoardWidget;

class PlayTttApplication : public QApplication
{
    Q_OBJECT
public:
    typedef QChar Token;
    typedef QVector<Token> TokenVector;
    typedef QVector<int> IndexVector;

public:
    PlayTttApplication(int &argc, char **argv);
    MainWindow *mainWindow() { return mpMainWindow; }
    TttMachine *machine() { return mpMachine; }
    TttBoardWidget *board();
    Random random() { return mRandom; }

public:
    Token crossToken() const { return cmCrossToken; }
    Token circleToken() const { return cmCircleToken; }

public:
    bool isHomeCurrentPlayer() { return mCurrentPlayer; }
    bool isVistorCurrentPlayer() { return ! isHomeCurrentPlayer(); }
    IndexVector availableIndicies();

public slots:
    void start(MainWindow *pMainWindow);
    void startMachine();
    void startPlay();
    void windowFinished() { mSetupFinished = true; }

private slots:
//    void setupActions();
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
    TttBoardWidget *mpBoardWidget=nullptr;
    Random mRandom;
    bool mSetupFinished=false;   // Needo: switch bool to Token
    bool mNextFirstPlayer=false;
    bool mCurrentPlayer=false;
    const Token cmNullToken = Token('*');
    const Token cmEmptyToken = Token(' ');
    const Token cmCrossToken = Token('X');
    const Token cmCircleToken = Token('O');
    TokenVector mCurrentTokens;
};
