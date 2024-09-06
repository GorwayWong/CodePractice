#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <stdbool.h>

bool isPowerOfThree(int n)
{
    if (n == 1)
        return false;
    while (n != 1)
    {
        if (n % 3 != 0)
        {
            return false;
        }
        else
        {
            n /= 3;
        }
    }
    return true;
}