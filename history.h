#ifndef HISTORY_H
#define HISTORY_H

#include <iostream>
#include "main.h"
#include <vector>

class history
{
    std::vector<long double> m_history {0};

    public:
    explicit history(long double history);

    void saveToHistory(long double result);
    void printHistory();
    void replaceBase(Exponenter num);

};

#endif