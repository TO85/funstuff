#pragma once

#include <QtCore/QQueue>
#include <QtCore/QRandomGenerator>
#include <QtCore/QVector>


class RandomF
{
public:
    typedef quint32 Word; // QRandomGenerator::generate() result
    typedef double Real; // QRandomGenerator::generateDouble() result
    typedef qsizetype Count;
    typedef QQueue<Real> RealQueue;
    typedef QVector<Real> RealVector;

public:
    RandomF() { mGenerator = QRandomGenerator::securelySeeded(); ctor(); }
    RandomF(const quint32 aSeed) { mGenerator = QRandomGenerator(aSeed); ctor(); }
    void ctor();

public:
    Count bufferCount() const { return mBufferQueue.count(); }

public:
    Real peek();
    Real take();

private:
    bool loadBuffer();
    void fillChunkBuffer(Count aCount=0);


private:
    QRandomGenerator mGenerator;
    RealQueue mBufferQueue;
    Count mBufferLowCount = 4; // refill mChunkBuffer when below
    Count mBufferFillCount = 16; // number of Chunks to refill at a time
};

