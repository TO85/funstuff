#pragma once

#include <QMainWindow>

#include <QtDebug>
class QGridLayout;
class QLayout;
class QLabel;

#include "TttPixmaps.h"
class ActionManager;
class ScoreWidget;
class TttBoardWidget;
class BottomWidget;

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    TttBoardWidget *board() { return mpTttBoardWidget; }
    ActionManager *actions() { return mpActions; }

public:

signals:
    void constructed();
    void setupComplete();

public slots:
    void construct();
    void setup();
    void displayMessage(const QString &aString);

private slots:
    void setupIcons();
    void setupWidgets();
    void setupLayout();
    void setupToolbar();
    void setupFinish();

private:
    ActionManager *mpActions=nullptr;
    QWidget *mpMainWidget=nullptr;
    QGridLayout *mpMainLayout=nullptr;
    ScoreWidget *mpScoreWidget=nullptr;
    TttBoardWidget *mpTttBoardWidget=nullptr;
    BottomWidget *mpBottomWidget=nullptr;
    const int cmShortShotMsec=10;
    QSize mIconSize=QSize(64, 64);
};
