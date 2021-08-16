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
        fillBuffer();
    return result;
}

void RandomF::fillBuffer(Count aCount)
{
    if (0 == aCount) aCount = mBufferFillCount;
    while (aCount > 0)
        mBufferQueue.append(mGenerator.generateDouble());
}
