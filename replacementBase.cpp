#include "replacementBase.h"

int replacementBase::m_replaceID {1};

replacementBase::replacementBase(Exponenter replaced)
    : m_baseReplace {replaced.m_intBase}
    {
    }

replacementBase::replaceBaseIDIncrement()
{
    std::cout << "You have changed bases to the result " << m_replaceID << " times\n";
    ++m_replaceID;
}

replacementBase::isEqual(Exponenter replaced)
{
    if (m_baseReplace == replaced.m_intBase)
    {
        return true;
    }
    else
    {
        return false;
    }
}