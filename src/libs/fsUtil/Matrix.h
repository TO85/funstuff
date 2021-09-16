#ifndef MATRIX_H
#define MATRIX_H

#include <QtCore/QSize>
#include <QtCore/QVector>

template <class T> class Matrix
{
public:
    Matrix(void) {}
    Matrix(const QSize size) { resize(size); }
    bool isEmpty(void) const { return mTVector.isEmpty(); }
    QSize size(void) const { return mSize; }
    int height(void) const { return mSize.height(); }
    int width(void) const { return mSize.width(); }
    void clear(void) { resize(mSize); }
    bool isValid(const int x, const int y) const
    { return x >= 0 && x < mSize.width() && y >= 0 && y < mSize.height(); }
    T at(const int x, const int y) const
    { return isValid(x, y) ? mTVector.at(index(x, y)) : T(); }
    T at(const QPoint pt) const
    { return at(pt.x(), pt.y()); }
    void set(const int x, const int y, const T t)
    {
        if (isValid(x, y))
        {
            mTVector.replace(index(x, y), t);
        }
        else
            qDebug("Matrix::set(%i,%i) invalid", x, y);
    }
    void resize(const QSize size)
    { fill(T(), size); }
    void fill(T t, QSize size)
    {
        if (size.isValid())
        {
            mSize = size;
            mTVector.fill(t, mSize.width() * mSize.height());
        }
        else
        {
            mSize = QSize();
            mTVector.clear();
        }
    }
    T * row(const int y)
    {
        return (y >= 0 && y < mSize.height())
                ? mTVector.data() + y * mSize.width() : 0;
    }
    const T * constRow(const int y) const
    {
        return (y >= 0 && y < mSize.height())
                ? mTVector.data() + y * mSize.width() : 0;
    }
    const T * data() { return mTVector.data(); }
    const QVector<T> vector() const { return mTVector; }
    QVector<T> &vector() { return mTVector; }
    Matrix operator += (Matrix other)
    {
        int n = mTVector.size();
        for (int x = 0; x < n; ++x)
            mTVector[x] += other.mTVector[x];
        return *this;
    }
    bool operator == (const Matrix other)
    {
        if (size() != other.size())     return false;
        if (vector() != other.vector()) return false;
        return true;
    }

private:
    int index(const int x, const int y) const
    { return y * mSize.width() + x; }

private:
    QSize mSize;
    QVector<T> mTVector;
};

#endif // MATRIX_H
