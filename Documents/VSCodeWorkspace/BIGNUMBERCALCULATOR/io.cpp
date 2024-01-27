#include "io.h"

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
    while ((x < 1) || (x > 6))
    {
        std::cout << "\nThe following functions are available:\n";
        std::cout << "\t1. Addition\n";
        std::cout << "\t2. Subtraction\n";
        std::cout << "\t3. Multiplication\n";
        std::cout << "\t4. Division\n";
        std::cout << "\t5. Further functions (INTEGER ONLY)\n";
        std::cout << "\t6. Return to Menu\n";
        std::cout << "Please enter a number: ";
        std::cin >> x;
    }
    return x;
}

int printExpFunctionMenu()
{
    int x {-1};
    while ((x < 1) || (x > 4))
    {   
        std::cout << "\nThe following functions are available:\n";
        std::cout << "\t1. Exponentiation\n";
        std::cout << "\t2. Factorial\n";
        std::cout << "\t3. Back\n";
        std::cout << "\t4. Return to Menu\n";
        std::cout << "Please enter a number: ";
        std::cin >> x;
    }
    return x;
}