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

private:
    QSharedDataPointer<RandomExec> x;

// RandomInterface interface
public:
    bool peekBit() const { return x->peekBit(); }
    Word peekWord() const  { return x->peekWord(); }
    bool takeBit() { return x->takeBit(); }
    Word takeWord()  { return x->takeWord(); }
};
