#pragma once

#include <QWidget>

#include <QtCore/QVector>
#include <QtGui/QIcon>
#include <QtGui/QPixmap>
#include <QtWidgets/QLabel>

class QGridLayout;

#include "MainWindow.h"
class IconFactory;

class T3BoardWidget : public QWidget
{
    Q_OBJECT
public:
    explicit T3BoardWidget(MainWindow *parent = nullptr);
    MainWindow * mainWindow() { return mpMainWindow; }
    QSize iconSize() const { return mIconSize; }

public slots:
    void clearBoard();
    void setIconAt(const int aIndex, const QIcon aIcon);
    void setupLayout();

private:
    int index(const int row, const int col) const;
    int indexFromLayout(const int aLayoutRow, const int aLayoutCol) const;
    int gridEntries() const;
    int row(const int aIndex) const;
    int col(const int aIndex) const;
    int layoutRow(const int aIndex) const;
    int layoutCol(const int aIndex) const;

private:
    void setIconAt(const int row, const int col, const QIcon aIcon);
    void setIconInLayout(const int aLayoutRow, const int aLayoutCol, const QIcon aIcon);
    void setPixmapAt(QLabel *pLabel, const QPixmap aPixmap);
    void setPixmapAt(const int aIndex, const QPixmap aPixmap);
    void setPixmapAt(const int aLayoutRow, const int aLayoutCol, const QPixmap aPixmap);

signals:

private:
    MainWindow *mpMainWindow=nullptr;
    QGridLayout *mpMainLayout=nullptr;
    QVector<QLabel *> mLabelVector;
    QSize mGridSize=QSize(3, 3);
    QSize mIconSize=QSize(64, 64);
};

