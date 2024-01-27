#include "config.h"

bool debug {0};

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