#ifndef IO_H
#define IO_H

#include <iostream>
void printResult(auto result)
{
    if (result - (static_cast<long long int>(result)) == 0)
        std::cout << "Result: " << static_cast<long long int>(result) << '\n';
    else
        std::cout << "Result: " << result << '\n';
}

constexpr long long int getInteger()
{
    std::cout << "Enter an Integer: ";
    double x {};
    std::cin >> x;
    while (x - static_cast<int>(x))
    {
        std::cout << "\nPlease enter an integer, not any other number type: ";
        std::cin >> x;
    }
    return x;
}

constexpr long double getNumber()
{
    std::cout << "Enter a number: ";
    double x {};
    std::cin >> x;
    return x;
}

int printMainMenu();
int printFunctionMenu();
int printExpFunctionMenu();

#endif