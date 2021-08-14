#include "RandomF.h"


void RandomF::ctor()
{
    void peek();
}

RandomF::Real RandomF::peek()
{
    loadBuffer();
    return mBufferQueue.first();
}

RandomF::Real RandomF::take()
{
    loadBuffer();
    return mBufferQueue.takeFirst();
}

bool RandomF::loadBuffer()
{
    bool result = bufferCount() < mBufferLowCount;
    if (result)
        fillChunkBuffer();
    return result;
}

void RandomF::fillChunkBuffer(Count aCount)
{
    if (0 == aCount) aCount = mBufferFillCount;
    while (aCount > 0)
        mBufferQueue.append(mGenerator.generateDouble());
}
