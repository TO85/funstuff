#include "RandomExec.h"

RandomExec::RandomExec() : cmpGenerator(new QRandomGenerator) {;}

void RandomExec::seed(const quint32 aSeed)
{
    cmpGenerator->seed(aSeed);
}

/* ------------------------- private ----------------------- */

RandomInterface::Count RandomExec::wordBufferCount() const
{
    Count result = 0;
    for (WordVector wv : mWordBuffer)
        result += wv.count();
    return result;
}


void RandomExec::adjustBitCounts(const Count aBitCount)
{
    if (mBitsLowCount < 2 * aBitCount)
        mBitsLowCount = 2 * aBitCount;
    if (mBitsFillCount < 2 * mBitsLowCount)
        mBitsFillCount = 4 * mBitsLowCount;
}

void RandomExec::adjustWordCounts(const Count aWordCount) const
{
    if (mWordLowCount < 2 * aWordCount)
        mWordLowCount = 2 * aWordCount;
    if (mBitsFillCount < 2 * mWordLowCount)
        mWordFillCount = 4 * mWordLowCount;
}

RandomInterface::Count RandomExec::fillBitBuffer(const Count aBitCount) const
{

}

RandomInterface::Count RandomExec::fillWordBuffer(const Count aWordCount) const
{
    Count result = mWordBuffer.count();
    if (result > aWordCount) return result;                             /* /====\ */
    adjustWordCounts(aWordCount);
    QVector<Word> tNewVector(mWordFillCount);
    QRandomGenerator::global()->fillRange(tNewVector.data(), tNewVector.size());
    mWordBuffer.append(tNewVector);
    result = wordBufferCount();
    return result;
}

/* ------------------------- RandomInterface interface ----------------------- */

bool RandomExec::peekBit() const
{
    return mBitWord & mBitMask;
}

RandomInterface::Word RandomExec::peekWord() const
{
    fillWordBuffer(2);
    Q_ASSERT( ! mWordBuffer.isEmpty());
    Q_ASSERT( ! mWordBuffer.first().isEmpty());
    return mWordBuffer.first().first();
}

bool RandomExec::takeBit()
{
    bool result = peekBit();
    mBitMask >>= 1;
    if (0 == mBitMask)
        mBitWord = takeWord();
    return result;
}

RandomInterface::Word RandomExec::takeWord()
{
    Word result = peekWord();
    void(mWordBuffer.first().takeFirst());
    while (mWordBuffer.first().isEmpty())
        void(mWordBuffer.takeFirst());
    return result;
}
