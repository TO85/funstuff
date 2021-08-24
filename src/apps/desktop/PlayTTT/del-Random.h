#pragma once

#include <QtCore/QBitArray>
#include <QtCore/QQueue>
#include <QtCore/QRandomGenerator>
#include <QtCore/QVector>

class Random
{
public:
    typedef quint32 Word; // QRandomGenerator::generate() result
    typedef double Real; // QRandomGenerator::generateDouble() result
    typedef qsizetype Count;
    typedef QVector<Word> WordVector;
    typedef QVector<WordVector> WordVectorVector;

public:
    Random() { mGenerator = QRandomGenerator::securelySeeded(); ctor(); }
    Random(const quint32 aSeed) { mGenerator = QRandomGenerator(aSeed); ctor(); }
    void ctor();

public:
    Count bufferWordCount() const { return mBufferWordCount; }
    
public:
    Word peek(const Word aBound);
    Word take(const Word aBound);
    Word peekWord();
    Word takeWord();
    WordVector peekWords(const Count aWordCount);
    WordVector takeWords(const Count aWordCount);
    bool peekBit();
    bool takeBit();
    QBitArray peekBits(const Count aBitCount);
    QBitArray takeBits(const Count aBitCount);

private:
    void chop(const Count aCount);
    Count loadCurrent();
    void currentTakeBufferFirst();
    bool checkBuffer(const Count aWordCount=1);
    bool loadBuffer(const Count aWordCount=1);
    void fillChunkBuffer(const Count aWordCount=1);
    WordVector generateVector(Count aWordCount=0);
    WordVectorVector generateVectors(Count aVectorCount=0, const Count aWordCount=0);
    void enqueueBuffer(const WordVectorVector aVectors);

private:
    QRandomGenerator mGenerator;
    unsigned mBits=0;
    unsigned mBitMask=0;
    Count mWordVectorCount = 16; // number of Words in Vector
    Count mBufferLowCount = 4; // refill mChunkBuffer when below
    Count mBufferFillCount = 16; // number of Chunks to refill at a time
    WordVector mCurrentChunk;
    Count mBufferWordCount = 0;
    QQueue<WordVector> mWordVectorBuffer;
};
