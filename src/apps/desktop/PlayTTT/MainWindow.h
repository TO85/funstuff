#pragma once

#include <QMainWindow>

class QGridLayout;

class ScoreWidget;
class T3BoardWidget;
class BottomWidget;

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

public slots:
    void setup();

private:
    QWidget *mpMainWidget=nullptr;
    QGridLayout *mpMainLayout=nullptr;
    ScoreWidget *mpScoreWidget=nullptr;
    T3BoardWidget *mpT3BoardWidget=nullptr;
    BottomWidget *mpBottomWidget=nullptr;

};
