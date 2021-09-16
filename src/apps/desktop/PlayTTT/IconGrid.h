#pragma once

#include <QtWidgets/QWidget>

#include <QtGui/QIcon>
#include <QtGui/QPixmap>
class QFrame;
class QLabel;
class QVBoxLayout;
#include <QtCore/QPoint>
#include <QtCore/QSize>
#include <QtGui/QIcon>
#include <QtGui/QPixmap>
#include <QtGui/QIcon>
#include <QtGui/QPixmap>
class QFrame;
class QLabel;
class QVBoxLayout;

#include <fsUtil/Matrix.h>


class IconGrid : public QWidget
{
    Q_OBJECT
public:
    explicit IconGrid(QWidget *parent = nullptr);

public:
    QSize overallSize() const;
    const Matrix<QLabel *> &labelMatrix() const;
    const Matrix<QPixmap> &pixmapMatrix() const;

public:
    void setCell(QPoint aCoordinate, const QIcon &aIcon,
                 const QIcon::Mode aMode=QIcon::Normal,
                 const QIcon::State aState=QIcon::Off);
    void setCell(QPoint aCoordinate, const QPixmap &aPixmap);
    void clearCell(QPoint aCoordinate);
    void clearCells();

private:
    void setup();
    void draw();
    void drawGrid();
    void drawCells();
    void drawCell(const QPoint aCoordinate);
    void drawCell(const int index);

private:
    QVBoxLayout *mpMainLayout=nullptr;
    QLabel *mpMainLabel=nullptr;
    QPixmap mMainPixmap;
    Matrix<QLabel *> mLabelMatrix;
    Matrix<QPixmap> mPixmapMatrix;
    QFrame *mpFrame=nullptr;
    QFrame *mpHDividerMemio=nullptr;
    QFrame *mpVDividerMemio=nullptr;

// Q_PROPERTYs
public:
    const QSize &gridSize() const;
    void setGridSize(const QSize &newGridSize);
    void resetGridSize();

    const QSize &iconSize() const;
    void setIconSize(const QSize &newIconSize);
    void resetIconSize();

    const QColor &cellColor() const;
    void setCellColor(const QColor &newCellColor);
    void resetCellColor();

    const QColor &backColor() const;
    void setBackColor(const QColor &newBackColor);
    void resetBackColor();

    int dividerWidth() const;

    int dividerMargin() const;
    void setDividerMargin(int newDividerMargin);
    void resetDividerMargin();

    int frameWidth() const;

    int frameMargin() const;
    void setFrameMargin(int newFrameMargin);
    void resetFrameMargin();

    QVBoxLayout *getMainLayout() const;
    QLabel *getMainLabel() const;
    const QPixmap &mainPixmap() const;
    void setMainPixmap(const QPixmap &newMainPixmap);
    void resetMainPixmap();
    int dividerLineWidth() const;
    void setDividerLineWidth(int newDividerLineWidth);
    void resetDividerLineWidth();
    int dividerMidWidth() const;
    void setDividerMidWidth(int newDividerMidWidth);
    void resetDividerMidWidth();
    const QString &dividerStyleSheet() const;
    void setDividerStyleSheet(const QString &newDividerStyleSheet);
    void resetDividerStyleSheet();
    int frameLineWidth() const;
    void setFrameLineWidth(int newFrameLineWidth);
    void resetFrameLineWidth();
    int frameMidWidth() const;
    void setFrameMidWidth(int newFrameMidWidth);
    void resetFrameMidWidth();
    const QString &frameStyleSheet() const;
    void setFrameStyleSheet(const QString &newFrameStyleSheet);
    void resetFrameStyleSheet();

    QFrame *getMpFrame() const;
    void setMpFrame(QFrame *newMpFrame);
    QFrame *getMpHDividerMemio() const;
    void setMpHDividerMemio(QFrame *newMpHDividerMemio);
    QFrame *getMpVDividerMemio() const;
    void setMpVDividerMemio(QFrame *newMpVDividerMemio);

signals:
    void gridSizeChanged();
    void iconSizeChanged();
    void cellColorChanged();
    void backColorChanged();
    void dividerWidthChanged();
    void dividerMarginChanged();
    void frameWidthChanged();
    void frameMarginChanged();

    void mpMainLayoutChanged();
    void mpMainLabelChanged();
    void mainPixmapChanged();
    void labelMatrixChanged();
    void pixmapMatrixChanged();
    void dividerLineWidthChanged();
    void dividerMidWidthChanged();
    void dividerStyleSheetChanged();
    void frameLineWidthChanged();
    void frameMidWidthChanged();
    void frameStyleSheetChanged();

    void mpFrameChanged();
    void mpHDividerMemioChanged();
    void mpVDividerMemioChanged();

private:
    QSize mGridSize;
    QSize mIconSize;
    QColor mCellColor;
    QColor mBackColor;
    int mDividerWidth; // r/o
    int mDividerLineWidth;
    int mDividerMidWidth;
    QString mDividerStyleSheet;
    int mDividerMargin;
    int mFrameWidth; // r/o
    int mFrameLineWidth;
    int mFrameMidWidth;
    QString mFrameStyleSheet;
    int mFrameMargin;
    Q_PROPERTY(QSize gridSize READ gridSize WRITE setGridSize RESET resetGridSize NOTIFY gridSizeChanged)
    Q_PROPERTY(QSize iconSize READ iconSize WRITE setIconSize RESET resetIconSize NOTIFY iconSizeChanged)
    Q_PROPERTY(QColor cellColor READ cellColor WRITE setCellColor RESET resetCellColor NOTIFY cellColorChanged)
    Q_PROPERTY(QColor backColor READ backColor WRITE setBackColor RESET resetBackColor NOTIFY backColorChanged)
    Q_PROPERTY(int dividerWidth READ dividerWidth NOTIFY dividerWidthChanged)
    Q_PROPERTY(int dividerMargin READ dividerMargin WRITE setDividerMargin RESET resetDividerMargin NOTIFY dividerMarginChanged)
    Q_PROPERTY(int frameWidth READ frameWidth NOTIFY frameWidthChanged)
    Q_PROPERTY(int frameMargin READ frameMargin WRITE setFrameMargin RESET resetFrameMargin NOTIFY frameMarginChanged)
    Q_PROPERTY(int dividerLineWidth READ dividerLineWidth WRITE setDividerLineWidth RESET resetDividerLineWidth NOTIFY dividerLineWidthChanged)
    Q_PROPERTY(int dividerMidWidth READ dividerMidWidth WRITE setDividerMidWidth RESET resetDividerMidWidth NOTIFY dividerMidWidthChanged)
    Q_PROPERTY(QString dividerStyleSheet READ dividerStyleSheet WRITE setDividerStyleSheet RESET resetDividerStyleSheet NOTIFY dividerStyleSheetChanged)
    Q_PROPERTY(int frameLineWidth READ frameLineWidth WRITE setFrameLineWidth RESET resetFrameLineWidth NOTIFY frameLineWidthChanged)
    Q_PROPERTY(int frameMidWidth READ frameMidWidth WRITE setFrameMidWidth RESET resetFrameMidWidth NOTIFY frameMidWidthChanged)
    Q_PROPERTY(QString frameStyleSheet READ frameStyleSheet WRITE setFrameStyleSheet RESET resetFrameStyleSheet NOTIFY frameStyleSheetChanged)
    Q_PROPERTY(QFrame * mpFrame READ getMpFrame WRITE setMpFrame NOTIFY mpFrameChanged)
    Q_PROPERTY(QFrame * mpHDividerMemio READ getMpHDividerMemio WRITE setMpHDividerMemio NOTIFY mpHDividerMemioChanged)
    Q_PROPERTY(QFrame * mpVDividerMemio READ getMpVDividerMemio WRITE setMpVDividerMemio NOTIFY mpVDividerMemioChanged)
};

