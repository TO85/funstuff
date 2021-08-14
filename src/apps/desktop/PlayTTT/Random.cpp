#include "Random.h"

void Random::ctor()
{
    void(peekWord());
}

Random::Word Random::peekWord()
{
    loadCurrent();
    return mCurrentChunk.first();
}

/* ------------------------- private ------------------------- */

Random::Count Random::loadCurrent()
{
    loadBuffer();
    if (mCurrentChunk.isEmpty())
        currentTakeBufferFirst();
    return mCurrentChunk.count();
}

void Random::currentTakeBufferFirst()
{
    WordVector tChunk = mWordVectorBuffer.takeFirst();
    mBufferWordCount -= tChunk.count();
    mCurrentChunk.append(tChunk);
}

bool Random::checkBuffer(const Count aWordCount)
{   // adjusts working parameters for larger requests
    bool result = aWordCount > mBufferLowCount;
    if (result)
    {
        // TODO powerOfTwo()
        mWordVectorCount = 2 * aWordCount;
        mBufferLowCount = 4 * mWordVectorCount;
        mBufferFillCount = 4 * mBufferLowCount;
    }
    return result;
}

bool Random::loadBuffer(const Count aWordCount)
{   // ensures mBuffer has enough
    bool result = checkBuffer(aWordCount);
    if (result) fillChunkBuffer(aWordCount);
    return result;
}

void Random::fillChunkBuffer(const Count aWordCount)
{
    while (bufferWordCount()
                < qMax(mBufferLowCount, aWordCount))
        enqueueBuffer(generateVectors());
}

Random::WordVector Random::generateVector(Count aWordCount)
{
    if (0 == aWordCount) aWordCount = mWordVectorCount;
    WordVector result(aWordCount);
    mGenerator.fillRange(result.data(), result.count());
    return result;
}

Random::WordVectorVector Random::generateVectors(Count aVectorCount, Count aWordCount)
{
    if (0 == aWordCount) aWordCount = mWordVectorCount;
    if (0 == aVectorCount) aVectorCount = mBufferFillCount;
    WordVectorVector result;
    while (aVectorCount > 0)
    {
        WordVector tChunk = generateVector(aWordCount);
        result.append(tChunk);
        --aVectorCount;
    }
    return result;
}

void Random::enqueueBuffer(const WordVectorVector aVectors)
{
    for ( WordVector tChunk : aVectors)
    {
        mWordVectorBuffer.enqueue(tChunk);
        mBufferWordCount += tChunk.count();
    }
}

            
