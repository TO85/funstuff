#pragma once

#include <QtCore/QLinkedList>

class Ramdom
{
    Random() { mGenerator = QRandomGenerator::securelySeeded(); }
    Random(const quint32 aSeed) { mGenerator = QRandomGenerator(aSeed); }
    
private:
    void checkBuffer(const qsizetype mWordCount);
    // Adjust mBufferLowCount to mWordCount (and mBufferLoadCount)
    // Load more to mBuffer if necessary

private:
    QRandomGenerator mGenerator;
    unsigned mBits=0;
    unsigned mBitMask=0;
    unsigned mBufferLowCount = 16;
    unsigned mBufferFillCount = 64;
    QLinkedList<unsigned> mBuffer;
}
