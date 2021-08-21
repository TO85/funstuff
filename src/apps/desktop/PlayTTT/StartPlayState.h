#pragma once

#include <QState>
#include <QObject>

class QPushButton;
class QVBoxLayout;
class QWidget;

class PlayTttApplication;

class StartPlayState : public QState
{
    Q_OBJECT
public:
    StartPlayState(PlayTttApplication * pApplication);
    ~StartPlayState() {;}
    PlayTttApplication *application() { return mpApplication; }

public slots:
    void setup();

private:
    PlayTttApplication *mpApplication=nullptr;
    QWidget *mpMainWidget=nullptr;
};

