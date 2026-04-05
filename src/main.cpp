#include <iostream>

#include "app.h"

int main()
{
    try
    {
        App app;
        app.Run();
    }
    catch (const std::exception& e)
    {
        std::cerr << e.what() << '\n';
        return 1;
    }

    return 0;
}
