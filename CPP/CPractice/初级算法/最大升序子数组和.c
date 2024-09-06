#include <stdlib.h>
#include <stdio.h>
#include <math.h>

int maxAscendingSum(int *nums, int numsSize)
{
    if (nums == NULL)
        return 0;
    int result = 0;
    int tempSum;
    for (int i = 0; i < numsSize; i++)
    {
        tempSum = nums[i];
        while (i + 1 < numsSize && nums[i + 1] > nums[i])
        {
            tempSum += nums[i + 1];
            i++;
        }
        if (tempSum > result)
            result = tempSum;
    }
    return result;
}