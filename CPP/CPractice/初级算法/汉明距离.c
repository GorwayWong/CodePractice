#include <stdlib.h>
#include <stdio.h>
#include <math.h>

int hammingDistance(int x, int y)
{
    int result = 0;
    unsigned int xComparey = x ^ y;
    int count = 0;
    int temp;
    while (xComparey != 0)
    {
        temp = xComparey & 1;
        if (temp == 1)
            count++;
        xComparey>>1;
    }
    return count;
}