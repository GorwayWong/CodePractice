#include <stdlib.h>
#include <stdio.h>
#include <math.h>

int rob(int *nums, int numsSize)
{
    if (nums == NULL)
        return 0;
    else if (numsSize == 1)
        return nums[0];
    int *maxProfit = (int *)malloc(sizeof(int) * (numsSize + 1));
    maxProfit[0] = nums[0];
    maxProfit[1] = fmax(maxProfit[0], nums[1]);
    for (int i = 2; i < numsSize; i++)
    {
        // 要么偷掉当前房子的钱和前i-2个房子中能偷到的最多的钱
        // 要么偷前i-1个房子能偷到的最多钱 当前房子不偷了
        maxProfit[i] = fmax(maxProfit[i - 2] + nums[i], maxProfit[i - 1]);
    }
    int result = maxProfit[0];
    for (int i = 0; i < numsSize; i++)
    {
        if (maxProfit[i] > result)
            result = maxProfit[i];
    }
    return result;
}