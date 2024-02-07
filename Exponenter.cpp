#include "Exponenter.h"
#include "config.h"

Exponenter::Exponenter(long double intBase)
    : m_intBase {intBase}
{
    std::cout << "Constructed Number with value: " << m_intBase << '\n';
}

double Exponenter::add(const double& b)
{
    std::cout << "Evaluating: " << m_intBase << " + " << b << '\n';
    return (m_intBase + b);
}

double Exponenter::subtract(const double& b)
{
    std::cout << "Evaluating: " << m_intBase << " - " << b << '\n';
    return (m_intBase - b);
}

double Exponenter::multiply(const double& b)
{
    std::cout << "Evaluating: " << m_intBase << " * " << b << '\n';
    return (m_intBase * b);
}

double Exponenter::divide(const double& b)
{
    std::cout << "Evaluating: " << m_intBase << " / " << b << '\n';
    return (m_intBase / b);
}

double Exponenter::power(const int& intExp)
{
    while (!(isInteger()))
    {
        std::cout << "Functionality for non-integer exponentiation has not been added yet.";
        replaceInteger();
    }
    std::cout << "Evaluating " << m_intBase << " raised to the power of " << intExp << '\n';
    long long int temp {static_cast<long long int>(m_intBase)};
    long double overflowVar {};
    if (intExp >= 1)
    {
        for (int i {1}; i < intExp; ++i)
        {
            if (debug)
            {
                printExpDebugInfo(temp, i);
            }
            long long int prevTemp = temp;
            temp *= m_intBase;
            if (temp != 0)
            {
                overflowVar = temp / prevTemp;
            }
            if (overflowCheck(temp, prevTemp, overflowVar))
            {
                printIntOverflowError(i);
                long double temp2 {static_cast<double>(prevTemp)};
                for (int k {i}; k < intExp; ++k)
                {
                    if (debug)
                    {
                        printExpDebugInfo(temp2, ((k - i) + 1), k);
                    }
                    temp2 *= m_intBase;
                    if (temp2 > std::numeric_limits<double>::max())
                    {
                        printDoubleOverflowError();
                        return EXIT_FAILURE;
                    }
                }
                std::cout << "Be wary of floating point errors!\n";
                return temp2;
            }
        }
        return temp;
    }
    if ((intExp == 0) || (m_intBase == 1))
    {
        return 1;
    }
    if (intExp <= -1)
    {
        for (int i {1}; i < -intExp; ++i)
        {
            if (debug)
            {
                printExpDebugInfo(temp, i);
            }
            long long int prevTemp = temp;
            temp = temp * m_intBase;
            overflowVar = temp / prevTemp;
            if (overflowCheck(temp, prevTemp, overflowVar))
            {
                printIntOverflowError(i);
                long double temp2 {static_cast<double>(prevTemp)};
                for (int k {i}; k < -intExp; ++k)
                {
                    if (debug)
                    {
                        printExpDebugInfo(temp2, ((k - i) + 1), k);
                    }
                    temp2 *= m_intBase;
                    if (temp2 > std::numeric_limits<double>::max())
                    {
                        printDoubleOverflowError();
                        return EXIT_FAILURE;
                    }
                }
                std::cout << "Be wary of floating point errors!\n";
                return (1.0 / temp2);
            }
        }
        return (1.0 / temp);
    }
    return EXIT_FAILURE;
}

double Exponenter::factorial()
{
    while ((m_intBase < 0) || m_intBase > INT64_MAX || (!(isInteger())))
    {
        std::cerr << "Error: Factorial can only be applied to positive integers below INT64_MAX.\n";
        replaceInteger();
    }
    std::cout << "Evaluating " << m_intBase << '!' << '\n';
    unsigned long long int temp {static_cast<unsigned long long int>(m_intBase)};
    long double overflowVar {};
    for (long long int i {static_cast<long long int>(m_intBase) - 1}; i > 1; --i)
    {
        unsigned long long int prevTemp = temp;
        temp *= i;
        if (debug)
        {
            printFactorialDebugInfo(prevTemp, i, (m_intBase - i));
        }
        overflowVar = temp / prevTemp;
        if (overflowCheck(temp, prevTemp, overflowVar))
        {
            std::cerr << "Integer Overflow Detected at factorial() on iteration: " << (m_intBase - i) << '\n' <<
                "Falling back to double-precison floating-point format.\n";
            long double temp2 {static_cast<long double>(prevTemp)};
            for (long long int k {i}; k > 1; --k)
            {
                if (debug)
                {
                    printFactorialDebugInfo(temp2, k, ((i - k) + 1), (m_intBase - k));
                }
                temp2 *= k;
                if (temp2 > std::numeric_limits<double>::max())
                {
                    printDoubleOverflowError();
                    return EXIT_FAILURE;
                }
            }
            std::cout << "Be wary of floating point errors!\n";
            return temp2;
        }
    }
    return temp;
}

void Exponenter::saveToBase(const long double& result)
{
    m_intBase = result;
}

long double Exponenter::readBase()
{
    return m_intBase;
}

bool Exponenter::overflowCheck(auto& currentValue, auto& lastValue, auto& overflowVar) 
{
    if ((currentValue != overflowVar * lastValue) || (currentValue < lastValue))
        return true;
    else
        return false;
}

void Exponenter::replaceInteger()
{
    std::cout << "Enter an integer: ";
    long double x {m_intBase};
    std::cin >> x;
    while (x < INT64_MAX)
    {
        while ((x - static_cast<long long int>(x)) != 0)
        {
            std::cout << "\nPlease enter an integer, not any other number type: ";
            std::cin >> x;
        }
        break;
    }
    m_intBase = x;
}

void Exponenter::printBase()
{
    std::cout << "\nYour current base integer is: " << m_intBase << '\n';
}

void Exponenter::printIntOverflowError(int& i)
{
    std::cerr << "Error: Integer Overflow Detected on iteration: " << i << '\n' <<
    "Falling back to double-precison floating-point format.\n";
}

void Exponenter::printDoubleOverflowError()
{
    std::cerr << "Error: Result exceeded FP64 Limit of 1.8e+308.\n" <<
    "These numbers are beyond this calculator's capabilities.\n" <<
    "Please lower the base or exponent to fit the number.\n";
}

void Exponenter::printExpDebugInfo(long long int& temp, int& i)
{
    std::cout << temp << '\n';
    std::cout << "Looped " << i << " time(s).\n";
}

void Exponenter::printExpDebugInfo(long double& temp, const int& i, int& k)
{
    std::cout << temp << '\n';
    std::cout << "Double-precision arithmetic looped " << i <<
    " time(s). Total " << k << " time(s).\n";
}

void Exponenter::printFactorialDebugInfo(long long unsigned int& temp, long long int& i, const int& loop)
{
    std::cout << temp << '\n';
    std::cout << "Multiplying by " << i << ", Looped " << loop << " time(s).\n";
}

void Exponenter::printFactorialDebugInfo(long double& temp2, long long int& k, const long long int& i, const int& loop)
{
    std::cout << temp2 << '\n';
    std::cout << "Multiplying by " << k << ", Double-precision arithmetic looped " <<
        i << " time(s). Total " << loop << " time(s).\n";
}

bool Exponenter::isInteger()
{
    if (((m_intBase - static_cast<long long int>(m_intBase)) == 0) || (m_intBase > INT64_MAX))
    {
        return true;
    }
    else
    {
        return false;
    }
}
