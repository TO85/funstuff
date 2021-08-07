#pragma once

#include <QWidget>

#include <QtCore/QVector>
#include <QtGui/QIcon>
#include <QtGui/QPixmap>
#include <QtWidgets/QLabel>

class QGridLayout;

class T3BoardWidget : public QWidget
{
    Q_OBJECT
public:
    explicit T3BoardWidget(QWidget *parent = nullptr);

public slots:
    void setup();
    void setIconAt(const int row, const int col, const QIcon aIcon);

private:
    int index(const int row, const int col) const;
    int indexFromLayout(const int aLayoutRow, const int aLayoutCol) const;
    int gridEntries() const;
    int row(const int aIndex) const;
    int col(const int aIndex) const;
    int layoutRow(const int aIndex) const;
    int layoutCol(const int aIndex) const;

private:
    void setIconAt(const int aIndex, const QIcon aIcon);
    void setIconInLayout(const int aLayoutRow, const int aLayoutCol, const QIcon aIcon);
    void setPixmapAt(const int aIndex, const QPixmap aPixmap);
    void setPixmapAt(const int aLayoutRow, const int aLayoutCol, const QPixmap aPixmap);

private: // static
    static QLabel blankPixmapLabel(const QSize aSize=QSize(64,64));


signals:

private:
    QGridLayout *mpMainLayout=nullptr;
    QVector<QLabel *> mLabelVector;
    QSize mGridSize=QSize(3, 3);
    QSize mIconSize=QSize(64, 64);
};

