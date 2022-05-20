#include "ram.h"

int compute ()
{
    int result = 0;
    for(int i = 0; i < 8; i++)
    {
        result += read(i);
    }
    return result;
}
