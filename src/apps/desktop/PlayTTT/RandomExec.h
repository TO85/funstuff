#pragma once

#include <QtCore/QBitArray>
#include <QtCore/QList>
#include <QtCore/QRandomGenerator>
#include <QtCore/QSharedData>

//#include "Random.h"
#include "RandomInterface.h"

class RandomExec : public QSharedData, public RandomInterface
{
public:
    typedef QList<WordVector> WordVectorList;


public:
    RandomExec();
    void seed(const quint32 aSeed);

private:
    Count wordBufferCount() const;

private:
    QRandomGenerator const *generator() { return cmpGenerator; }
    void adjustBitCounts(const Count aBitCount);
    void adjustWordCounts(const Count aWordCount) const;
    Count fillBitBuffer(const Count aBitCount) const;
    Count fillWordBuffer(const Count aWordCount) const;
private:
    const Word cmWordMsb = 1 << (sizeof(Word) - 1);
    QRandomGenerator * const cmpGenerator;
    Word mBitWord=0;
    Word mBitMask=0;
    QBitArray mBitsBuffer;
    mutable WordVectorList mWordBuffer;
    Count mBitsLowCount= 4 * sizeof (Word);
    Count mBitsFillCount = 4 * mBitsLowCount;
    mutable Count mWordLowCount= 4;
    mutable Count mWordFillCount = 4 * mWordLowCount;


    // RandomInterface interface
public:
    bool peekBit() const;
    Word peekWord() const;
    bool takeBit();
    Word takeWord();

    // RandomInterface interface
public:
};

