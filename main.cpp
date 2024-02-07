#include "main.h"

int main()
{
    Exponenter number {getNumber()};
    int option {-1};
    history history {0};
    while (option != 5)
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
                long double result {};
                bool noResult {0};
                switch (printFunctionMenu())
                {
                    case 1:
                    {
                        result = number.add(getNumber());
                        printResult(result);
                        break;
                    }
                    case 2:
                    {
                        result = number.subtract(getNumber());
                        printResult(result);
                        break;
                    }
                    case 3:
                    {
                        result = number.multiply(getNumber());
                        printResult(result);
                        break;
                    }
                    case 4:
                    {
                        result = number.divide(getNumber());
                        printResult(result);
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
                                result = number.power(getNumber());
                                printResult(result);
                                break;
                            }
                            case 2:
                            {
                                result = number.factorial();
                                printResult(result);
                                break;
                            }
                            case 3:
                            {
                                noResult = 1;
                                break;
                            }
                        }
                        break;
                    }
                    case 6:
                    {
                        noResult = 1;
                        break;
                    }
                break;
                }
                if (!noResult)
                {
                    char x {-1};
                    while (!((x == 'y') || (x == 'n')))
                    {
                        std::cout << "Would you like to use this result as the next base? (y/n)\n";
                        x = getChar();
                    }
                    if (x == 'y')
                    {
                        history.saveToHistory(number.readBase());
                        number.saveToBase(result);
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
                history.printHistory();
                std::cout << "Do you want to change base to a stored number? (y/n)\n";
                char wantReplace {};
                std::cin >> wantReplace;
                if (wantReplace == 'y')
                {
                    history.replaceBase(number);
                }
                break;
            }
            case 5:
            case INT_MAX:
            case INT_MIN:
            {
                break;
            }
        }
    }
    return 0;
}