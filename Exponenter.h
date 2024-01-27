#ifndef EXPONENTER_H
#define EXPONENTER_H
#include <iostream>
#include <limits>

class Exponenter
{
    long double m_intBase {};

public:
    explicit Exponenter(long double m_intBase);
    double add(double b);
    double subtract(double b);
    double multiply(double b);
    double divide(double b);
    double power(int intExp);
    double factorial();
    bool overflowCheck(auto currentValue, auto lastValue, auto overflowVar);
    void replaceInteger();
    void printBase();
    void printIntOverflowError(int i);
    void printDoubleOverflowError();
    void printExpDebugInfo(long long int temp, int i);
    void printExpDebugInfo(long double temp, int i, int k);
    void printFactorialDebugInfo(long long int temp, int i, int loop);
    void printFactorialDebugInfo(long double temp2, int k, int i, int loop);
    bool isInteger();

};

#endif