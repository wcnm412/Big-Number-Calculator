#ifndef EXPONENTER_H
#define EXPONENTER_H
#include <iostream>
#include <limits>
#include <cstdint>

class Exponenter
{
    long double m_intBase {};

public:
    explicit Exponenter(long double m_intBase);
    double add(const double& b);
    double subtract(const double& b);
    double multiply(const double& b);
    double divide(const double& b);
    double power(const int& intExp);
    double factorial();
    void saveToBase(const long double& result);
    long double readBase();
    bool overflowCheck(auto& currentValue, auto& lastValue, auto& overflowVar);
    void replaceInteger();
    void printBase();
    void printIntOverflowError(int& i);
    void printDoubleOverflowError();
    void printExpDebugInfo(long long int& temp, int& i);
    void printExpDebugInfo(long double& temp, const int& i, int& k);
    void printFactorialDebugInfo(long long unsigned int& temp, long long int& i, const int& loop);
    void printFactorialDebugInfo(long double& temp2, long long int& k, const long long int& i, const int& loop);
    bool isInteger();
    friend class history;
};

#endif