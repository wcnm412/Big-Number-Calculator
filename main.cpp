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
                replacementBase replacer {};
                replacer.m_baseReplace = number.m_intBase;
                number.printBase();
                switch (printFunctionMenu())
                {
                    case 1:
                    {
                        replacer.m_baseReplace = number.add(getNumber());
                        printResult(replacer.m_baseReplace);
                        break;
                    }
                    case 2:
                    {
                        replacer.m_baseReplace = number.subtract(getNumber());
                        printResult(replacer.m_baseReplace);
                        break;
                    }
                    case 3:
                    {
                        replacer.m_baseReplace = number.multiply(getNumber());
                        printResult(replacer.m_baseReplace);
                        break;
                    }
                    case 4:
                    {
                        replacer.m_baseReplace = number.divide(getNumber());
                        printResult(replacer.m_baseReplace);
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
                                replacer.m_baseReplace = number.power(getNumber());
                                printResult(replacer.m_baseReplace);
                                break;
                            }
                            case 2:
                            {
                                replacer.m_baseReplace = number.factorial();
                                printResult(replacer.m_baseReplace);
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
                if (!replacer.isEqual(number))
                {
                    char x {-1};
                    while (!(x == 'y') || !(x == 'n'))
                    {
                        std::cout << "Would you like to use this result as the next base? (y/n)\n";
                        std::cin >> x;
                    }
                    if (x == 'y')
                    {
                        number.m_intBase = replacer.m_baseReplace;
                        replacer.replaceBaseIDIncrement();
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
            case INT_MAX:
            case INT_MIN:
            {
                break;
            }
        }
    }
    return 0;
}