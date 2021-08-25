#pragma once
#include <QtGlobal>

class QBitArray;

class RandomInterface
{
public:
    typedef unsigned Count;
    typedef quint32 Word;
    typedef double Float;
    typedef QVector<Word> WordVector;

public:
    virtual bool peekBit() const = 0;
    virtual QBitArray peekBits(const Count aBitCount) const = 0;
    virtual Word peekWord() const = 0;

public:
    virtual bool takeBit() = 0;
    virtual QBitArray takeBits(const Count aBitCount) = 0;
    virtual Word takeWord() = 0;

};
