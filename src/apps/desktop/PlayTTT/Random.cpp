#include "Random.h"

void Random::ctor()
{
    (void)peek();
}

unsigned peek() const
{
    if (mCurrentChunk.isEmpty())
        mCurrentChunk = takeBuffer();
    return mCurrentChunk.first();
}


// private
void checkBuffer(const qsizetype aWordCount)
{
    // Adjust buffer low and fill if necessary
    
    // Load buffer if necessary
}

QVector<unsigned> takeBuffer()
{
            
