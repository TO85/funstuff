#pragma once

#include <QMainWindow>

class QGridLayout;
class QLayout;
class QLabel;

class ScoreWidget;
class T3BoardWidget;
class BottomWidget;

#include "IconFactory.h"

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

public:
    IconFactory *factory() { return &mIconFactory; }

public slots:
    void setup();
    void displayMessage(const QString &aString);
    void showAt(const int aIndex, const QString &aKey);
    void showAt(QLabel *pLabel, const QString &aKey);

private slots:
    void setupIcons();

private:
    QWidget *mpMainWidget=nullptr;
    QGridLayout *mpMainLayout=nullptr;
    ScoreWidget *mpScoreWidget=nullptr;
    T3BoardWidget *mpT3BoardWidget=nullptr;
    BottomWidget *mpBottomWidget=nullptr;
    QSize mIconSize=QSize(64, 64);
    IconFactory mIconFactory;
};
