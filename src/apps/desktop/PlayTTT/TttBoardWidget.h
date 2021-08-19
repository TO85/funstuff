#pragma once

#include <QWidget>

#include <QtCore/QVector>
#include <QtGui/QIcon>
#include <QtGui/QPixmap>
#include <QtWidgets/QLabel>

class QGridLayout;

#include "TttPixmaps.h"
class MainWindow;

class TttBoardWidget : public QWidget
{
    Q_OBJECT
public:
    explicit TttBoardWidget(MainWindow *parent = nullptr);

public:
    QSize iconSize() const { return mIconSize; }
    int gridEntries() const;

public slots:
    void clearBoard();
    void setIconAt(const int aIndex, const QIcon aIcon);
    void setupPixmaps();
    void setupLayout();
    void showAt(const int aIndex, const TttPixmaps::Keys &aKeyStack);
    void showAt(QLabel *pLabel, const int aPixmapKeyStack);

private:
    int index(const int row, const int col) const;
    int indexFromLayout(const int aLayoutRow, const int aLayoutCol) const;
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
    QGridLayout *mpMainLayout=nullptr;
    QVector<QLabel *> mLabelVector;
    QSize mGridSize=QSize(3, 3);
    QSize mGridCellSize=QSize(60, 60);
    QSize mIconSize=QSize(48, 48);
    TttPixmaps mPixmaps;
};

