#pragma once

#include <QtGlobal>
#include <QtCore/QSharedDataPointer>

#include "RandomExec.h"
#include "RandomInterface.h"

class Random : public RandomInterface
{
public:
    Random() { x = new RandomExec; }
    Random(const quint32 aSeed) { x = new RandomExec; x->seed(aSeed); }
    ~Random() {;}

private:
    QSharedDataPointer<RandomExec> x;

// RandomInterface interface
public:
    bool peekBit() const { return x->peekBit(); }
    QBitArray peekBits(const Count aBitCount) const  { return x->peekBits(aBitCount); }
    Word peekWord() const  { return x->peekWord(); }
    bool takeBit() { return x->takeBit(); }
    QBitArray takeBits(const Count aBitCount)  { return x->takeBits(aBitCount); }
    Word takeWord()  { return x->takeWord(); }

};
