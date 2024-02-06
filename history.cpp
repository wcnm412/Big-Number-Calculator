#include "history.h"

history::history(long double history)
    : m_history {history}
{
    std::cout << "Result added to history\n";
}

void history::saveToHistory(long double result)
{
    m_history.resize(m_history.capacity() + 1);
    m_history.back() = result;
}

void history::printHistory()
{
    for (int index : m_history)
    {
        std::cout << "At index " << index << " is " << m_history[index] << '\n';
    }
}

auto history::replaceBase(int newBaseIndex, Exponenter num)
{
    num.m_intBase = m_history[newBaseIndex];
}