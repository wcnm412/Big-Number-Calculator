#ifndef HISTORY_H
#define HISTORY_H

#include <iostream>
#include "main.h"
#include <vector>

class history
{
    std::vector<long double> m_history {0};
    size_t indexedValue {0};

    public:
    explicit history(long double history);

    void saveToHistory(const long double& result);
    void printHistory();
    void replaceBase(Exponenter num);

};

#endif