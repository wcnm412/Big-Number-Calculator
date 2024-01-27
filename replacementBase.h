#ifndef REPLACEMENTBASE_H
#define REPLACEMENTBASE_H

#include <iostream>
#include "Exponenter.h"

class replacementBase
{
    long double m_baseReplace {};
    static int m_replaceID;

public:
    explicit replacementBase(Exponenter replaced);

    void replaceBaseIDIncrement();

    bool isEqual(Exponenter replaced);

    friend printResult();
    friend printResult(replacementBase replacer)

};

#endif