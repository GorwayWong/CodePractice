#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int climbStairs(int n)
{
    int oneStep = 1; // 离最后的台阶1步
    int twoStep = 1; // 离最后的台阶2步
    int result = 0;  // 最后的方案数 f(0) = 1,f(1) = 1,f(2) = 2,f(3) = 3
    if (n == 1 || n == 0)
    {
        return 1;
    }
    for (int i = 0; i < n - 1; i++)
    {
        result = oneStep + twoStep;
        twoStep = oneStep;
        oneStep = result;
    }
    return result;
}