#pragma once

#include <QWidget>

class QGridLayout;
class QLabel;
class QLCDNumber;

class ScoreWidget : public QWidget
{
    Q_OBJECT
public:
    explicit ScoreWidget(QWidget *parent = nullptr);

public slots:
    void setup();


signals:

private:
    QGridLayout *mpMainGrid=nullptr;
    QLabel *mpHomeName=nullptr;
    QLabel *mpVisitorName=nullptr;
    QLCDNumber *mpHomeWins=nullptr;
    QLCDNumber *mpVisitorWins=nullptr;
    QLCDNumber *mpHomeScore=nullptr;
    QLCDNumber *mpVisitorScore=nullptr;

};

