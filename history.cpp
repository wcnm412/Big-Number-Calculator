#include "history.h"

history::history(long double history)
    : m_history {history}
{
    std::cout << "History vector initialised\n";
}

void history::saveToHistory(long double result)
{
    m_history.resize(m_history.size() + 1);
    m_history.back() = result;
    std::cout << "Previous base saved to history\n";
}

void history::printHistory()
{
    for (unsigned int index {0}; index < m_history.size(); ++index)
    {
        std::cout << "Index " << index << " : " << m_history[index] << '\n';
    }
}

void history::replaceBase(Exponenter num)
{
    std::cout << "Which indexed number would you like to use as the new base?\n";
    std::size_t x {getInteger()};
    num.m_intBase = m_history[x];
    std::cout << "Base now changed to: " << num.m_intBase << '\n';
}