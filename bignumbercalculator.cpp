#include <iostream>
#include <limits>

bool debug {0};

class Exponenter
{
    long long int m_intBase {};

public:
    
    explicit Exponenter(int intBase)
        : m_intBase {intBase}
    {
        std::cout << "Constructed Number with value: " << m_intBase << '\n';
    }
    
    double power(int intExp = 1)
    {
        std::cout << "Evaluating " << m_intBase << " raised to the power of " << intExp << '\n';
        long long int temp {m_intBase};
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
                    double temp2 {static_cast<double>(prevTemp)};
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
        if (intExp == 0)
        {
            return 1;
        }
        if (intExp <= -1)
        {
            for (int i {-1}; i > intExp; --i)
            {
                if (debug)
                {
                    printExpDebugInfo(temp, -i);
                }
                long long int prevTemp = temp;
                temp = temp * m_intBase;
                overflowVar = temp / prevTemp;
                if (overflowCheck(temp, prevTemp, overflowVar))
                {
                    printIntOverflowError(i);
                    double temp2 {static_cast<double>(prevTemp)};
                    for (int k {i}; k > intExp; --k)
                    {
                        if (debug)
                        {
                            printExpDebugInfo(temp2, ((i - k) - 1), -k);
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

    double factorial()
    {
        while (m_intBase < 0)
        {
            std::cerr << "Error: Factorial cannot be applied to a negative number.";
            replaceInteger();
        }
        std::cout << "Evaluating " << m_intBase << '!' << '\n';
        unsigned long long int temp {static_cast<unsigned long long int>(m_intBase)};
        long double overflowVar {};
        for (int i {static_cast<int>(m_intBase) - 1}; i > 1; --i)
        {
            unsigned long long int prevTemp = temp;
            temp *= i;
            if (debug)
            {
                printFactorialDebugInfo(temp, i, (m_intBase - i));
            }
            overflowVar = temp / prevTemp;
            if (overflowCheck(temp, prevTemp, overflowVar))
            {
                std::cerr << "Integer Overflow Detected at factorial() on iteration: " << (m_intBase - i) << '\n' <<
                    "Falling back to double-precison floating-point format.\n";
                long double temp2 {static_cast<long double>(prevTemp)};
                for (int k {i}; k > 1; --k)
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

    bool overflowCheck(auto currentValue, auto lastValue, auto overflowVar) 
    {
        if ((currentValue != overflowVar * lastValue) || (currentValue < lastValue))
            return true;
        else
            return false;
    }

    void replaceInteger()
    {
        std::cout << "\nEnter a new integer: ";
        std::cin >> m_intBase;
    }

    void printBase()
    {
        std::cout << "\nYour current base integer is: " << m_intBase << '\n';
    }

    void printIntOverflowError(int i)
    {
        std::cerr << "Error: Integer Overflow Detected on iteration: " << i << '\n' <<
        "Falling back to double-precison floating-point format.\n";
    }

    void printDoubleOverflowError()
    {
        std::cerr << "Error: Result exceeded FP64 Limit of 1.8e+308.\n" <<
        "These numbers are beyond this calculator's capabilities.\n" <<
        "Please lower the base or exponent to fit the number.\n";
    }

    void printExpDebugInfo(long long int temp, int i)
    {
        std::cout << temp << '\n';
        std::cout << "Looped " << i << " time(s).\n";
    }

    void printExpDebugInfo(long double temp, int i, int k)
    {
        std::cout << temp << '\n';
        std::cout << "Double-precision arithmetic looped " << i <<
        " time(s). Total " << k << " time(s).\n";
    }

    void printFactorialDebugInfo(long long int temp, int i, int loop)
    {
        std::cout << temp << '\n';
        std::cout << "Multiplying by " << i << ", Looped " << loop << " time(s).\n";
    }

    void printFactorialDebugInfo(long double temp2, int k, int i, int loop)
    {
        std::cout << temp2 << '\n';
        std::cout << "Multiplying by " << k << ", Double-precision arithmetic looped " <<
            i << " time(s). Total " << loop << " time(s).\n";
    }
};

void toggleDebugInfo()
{
    if (debug == 1)
    {
        debug = 0;
        std::cout << "Debug information now set to: DISABLED\n";
    }
    else
    {
        debug = 1;
        std::cout << "Debug information now set to: ENABLED\n";
    }
}

void printResult(auto result)
{
    if (result - (static_cast<long long int>(result)) == 0)
        std::cout << "Result: " << static_cast<long long int>(result) << '\n';
    else
        std::cout << "Result: " << result << '\n';
}

constexpr int getInteger()
{
    std::cout << "Enter an Integer: ";
    double x;
    std::cin >> x;
    while (x - static_cast<int>(x))
    {
        std::cout << "\nPlease enter an integer, not any other number type: ";
        std::cin >> x;
    }
    return x;
}

void printMainMenu()
{
    std::cout << "\nThe following options are available:\n";
    std::cout << "\t1. Enter a new base number\n";
    std::cout << "\t2. Perform a function on an existing number\n";
    std::cout << "\t3. Toggle debug information\n";
    std::cout << "\t4. Quit\n";
}

int printFunctionMenu()
{
    int x {-1};
    while ((x < 1) || (x > 3))
    {   
        std::cout << "\nThe following functions are available:\n";
        std::cout << "\t1. Exponentiation\n";
        std::cout << "\t2. Factorial\n";
        std::cout << "\t3. Return to Menu\n";
        std::cout << "Please enter a number: ";
        std::cin >> x;
    }
    return x;
}

int main()
{
    Exponenter number {getInteger()};
    int option {-1};
    while (option != 4)
    {
        printMainMenu();
        std::cin >> option;
        if ((option > 0) && (option < 5))
        {
            switch (option)
            {
                case 1:
                {
                    number.printBase();
                    number.replaceInteger();
                    break;
                }
                case 2:
                {
                    number.printBase();
                    switch (printFunctionMenu())
                    {
                        case 1:
                        {
                            printResult(number.power(getInteger()));
                            break;
                        }
                        case 2:
                        {
                            printResult(number.factorial());
                            break;
                        }
                        case 3:
                        {
                            break;
                        }
                    }
                    break;
                }
                case 3:
                {
                    toggleDebugInfo();
                    break;
                }
                case 4:
                {
                    break;
                }
            }
        }
    }
    return 0;
}
