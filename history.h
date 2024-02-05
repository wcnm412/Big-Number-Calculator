#ifndef HISTORY_H
#define HISTORY_H

#include <iostream>
#include "main.h"
#include <vector>

class history
{
    std::vector<long double> m_history {0};

    public:
    explicit history(auto history);

    void saveToHistory(auto result);
    void printHistory();
    auto replaceBase(int newBaseIndex, Exponenter num);

};

#endif