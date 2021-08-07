#pragma once

#include <QApplication>
#include <QWidget>

class PlayT3Application : public QApplication
{
    Q_OBJECT
public:
    PlayT3Application(int &argc, char **argv);
};

