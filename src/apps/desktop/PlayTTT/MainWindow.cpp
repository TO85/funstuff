#include "MainWindow.h"

#include <QtCore/QTimer>
#include <QtGui/QBrush>
#include <QtGui/QPainter>
#include <QtGui/QPen>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>

#include "ScoreWidget.h"
#include "TttBoardWidget.h"
#include "BottomWidget.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    qDebug(Q_FUNC_INFO);
    setObjectName("MainWindow:PlayTttApplication");
}

MainWindow::~MainWindow()
{
}

/* ------------------------- public slots ------------------------ */

void MainWindow::construct()
{
    qDebug(Q_FUNC_INFO);
    mpMainWidget = new  QWidget(this);
    mpMainLayout = new  QGridLayout(mpMainWidget);
    mpScoreWidget = new  ScoreWidget(this);
    mpT3BoardWidget = new  T3BoardWidget(this);
    mpBottomWidget = new  BottomWidget(mpMainWidget);
    emit constructed();
}

void MainWindow::setup()
{
    qDebug(Q_FUNC_INFO);
    QTimer::singleShot(100, this, &MainWindow::setupWidgets);
}

void MainWindow::displayMessage(const QString &aString)
{
    qDebug(Q_FUNC_INFO);
    mpBottomWidget->display(aString);
}

void MainWindow::showAt(const int aIndex, const QString &aKey)
{
    qDebug(Q_FUNC_INFO);
//    const QIcon tIcon = factory()->icon(aKey);
  //  mpT3BoardWidget->setIconAt(aIndex, tIcon);
}

void MainWindow::showAt(QLabel *pLabel, const QString &aKey)
{
    qDebug(Q_FUNC_INFO);
//    const QIcon tIcon = factory()->icon(aKey);
    //  pLabel->setPixmap(tIcon.pixmap(mIconSize));
}

/* ------------------------ private slots ------------------------ */

void MainWindow::setupWidgets()
{
    qDebug(Q_FUNC_INFO);
    mpScoreWidget->setup();
    mpT3BoardWidget->setupLayout();
    mpBottomWidget->setup();
    QTimer::singleShot(100, this, &MainWindow::setupIcons);
}

void MainWindow::setupIcons()
{
    qDebug(Q_FUNC_INFO);
    const QSize tSize = mIconSize;
    const QColor tHColor = Qt::red;
    const QColor tVColor = Qt::blue;

//    factory()->create("Empty", IconFactory::Empty, QColor(), tSize);
  //  factory()->create("Home", IconFactory::Cross, tHColor, tSize);
    //factory()->create("Visitor", IconFactory::Circle, tVColor, tSize);
    QTimer::singleShot(100, this, &MainWindow::setupLayout);
}

void MainWindow::setupLayout()
{
    qDebug(Q_FUNC_INFO);
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
    QTimer::singleShot(100, this, &MainWindow::setupFinish);
}

void MainWindow::setupFinish()
{
    qDebug(Q_FUNC_INFO);
    setCentralWidget(mpMainWidget);
    emit setupComplete();
}

