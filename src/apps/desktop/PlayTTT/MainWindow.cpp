#include "MainWindow.h"

#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>

#include "ScoreWidget.h"
#include "T3BoardWidget.h"
#include "BottomWidget.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , mpMainWidget(new QWidget(this))
    , mpMainLayout(new QGridLayout(mpMainWidget))
    , mpScoreWidget(new ScoreWidget(mpMainWidget))
    , mpT3BoardWidget(new T3BoardWidget(mpMainWidget))
    , mpBottomWidget(new BottomWidget(mpMainWidget))
{
}

MainWindow::~MainWindow()
{
}

void MainWindow::setup()
{
    mpScoreWidget->setup();
    mpT3BoardWidget->setup();
    mpBottomWidget->setup();
    mpMainLayout->setColumnMinimumWidth(0, 200);
    mpMainLayout->addWidget(mpScoreWidget, 0, 0);
    mpMainLayout->setRowMinimumHeight(0, 60);
    mpMainLayout->addWidget(mpT3BoardWidget, 1, 0, Qt::AlignHCenter | Qt::AlignVCenter);
    mpMainLayout->setRowMinimumHeight(1, 200);
    mpMainLayout->addWidget(mpBottomWidget, 2, 0);
    mpMainLayout->setRowMinimumHeight(2,  40);
    mpMainWidget->setMinimumHeight(360);
    mpMainWidget->setMinimumWidth(200);
    mpMainWidget->setLayout(mpMainLayout);
    setCentralWidget(mpMainWidget);
}

