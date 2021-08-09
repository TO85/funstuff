#pragma once

#include <QtCore/QLinkedList>
#include <QtCore/QVector>

class Ramdom
{
public:
    Random() { mGenerator = QRandomGenerator::securelySeeded(); ctor(); }
    Random(const quint32 aSeed) { mGenerator = QRandomGenerator(aSeed); ctor(); }
    void ctor();
    
public:
    unsigned peek() const;
    unsigned peek(const qsizetype aWordCount) const;
    
public:
    unsigned take();
    unsigned take(const qsizetype aWordCount);
    
private:
    void checkBuffer(const qsizetype mWordCount);
    // Adjust mBufferLowCount to mWordCount (and mBufferLoadCount)
    // Load more to mBuffer if necessary
    QVector<unsigned> takeBuffer();

private:
    QRandomGenerator mGenerator;
    unsigned mBits=0;
    unsigned mBitMask=0;
    unsigned mBufferChunkCount = 16;
    unsigned mBufferLowCount = 64;
    unsigned mBufferFillCount = 256;
    QVector<unsigned> mCurrentChunk;
    QLinkedList<QVector<unsigned>> mBuffer;
}
