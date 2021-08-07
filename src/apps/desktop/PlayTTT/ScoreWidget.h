#pragma once

#include <QWidget>

class QGridLayout;
class QLabel;
class QLCDNumber;

class MainWindow;

class ScoreWidget : public QWidget
{
    Q_OBJECT
public:
    explicit ScoreWidget(MainWindow *parent = nullptr);
    MainWindow * mainWindow() { return mpMainWindow; }

public slots:
    void setup();


signals:

private:
    MainWindow *mpMainWindow=nullptr;
    QGridLayout *mpMainGrid=nullptr;
    QLabel *mpHomeName=nullptr;
    QLabel *mpVisitorName=nullptr;
    QLabel *mpHomeTile=nullptr;
    QLabel *mpVisitorTile=nullptr;

    QLCDNumber *mpHomeWins=nullptr;
    QLCDNumber *mpVisitorWins=nullptr;
};

