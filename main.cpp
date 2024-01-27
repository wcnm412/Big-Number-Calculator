#include "main.h"

int main()
{
    Exponenter number {getNumber()};
    int option {-1};
    while (option != 4)
    {
        option = printMainMenu();
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
                        printResult(number.add(getNumber()));
                        break;
                    }
                    case 2:
                    {
                        printResult(number.subtract(getNumber()));
                        break;
                    }
                    case 3:
                    {
                        printResult(number.multiply(getNumber()));
                        break;
                    }
                    case 4:
                    {
                        printResult(number.divide(getNumber()));
                        break;
                    }
                    case 5:
                    {
                        while (!(number.isInteger()))
                        {
                            std::cout << "The following functions can only be applied to integers.\n";
                            number.replaceInteger();
                        }
                        switch (printExpFunctionMenu())
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
                    case 6:
                    {
                        break;
                    }
                break;
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
    return 0;
}

// TODO:

// FIX NEGATIVE BASE IMMEDIATELY FALLING BACK TO DOUBLE WHEN EXPONENTIATING (CREATIVE SOLUTION NEEDED)