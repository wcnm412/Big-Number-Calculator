#include "history.h"

history::history(long double history)
    : m_history {}
{
    m_history.reserve(10);
    std::cout << "History vector initialised with " << m_history.capacity() << " spaces\n";
}

void history::saveToHistory(const long double& result)
{
    if (((m_history.size() % 10) == 0) && (m_history.size() != 0))
    {
        m_history.reserve(10);
        std::cout << "History capacity reached. Allocating 10 more spaces for a total of " 
            << m_history.capacity() << '\n';
    }
    m_history.push_back(result);
    std::cout << "Previous base saved to history\n";
}

void history::printHistory()
{
    for (std::size_t index {0}; index < m_history.size(); ++index)
    {
        std::cout << "Index " << index << " : " << m_history[index] << '\n';
    }
}

void history::replaceBase(Exponenter num)
{
    std::cout << "Which indexed number would you like to use as the new base?\n";
    std::size_t x {static_cast<size_t>(getInteger())};
    num.m_intBase = m_history[x];
    std::cout << "Base now changed to: " << num.m_intBase << '\n';
}