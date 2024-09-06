#include<stdlib.h>
#include<stdio.h>
#include<stdbool.h>
#include<math.h>

int maxSubArray(int* nums, int numsSize) {
    if(nums==NULL) return 0;
    int* maxSum=(int*)malloc(sizeof(int)*(numsSize+1));//maxSum[i]表示第i个元素前的子序列的最大子序列和
    maxSum[0]=nums[0];
    for (int i = 1; i < numsSize; i++)
    {
        maxSum[i] = fmax(maxSum[i-1]+nums[i],nums[i]);
    }
    int result=maxSum[0];
    for (int i = 0; i < numsSize; i++)
    {
        if(maxSum[i]>result){
            result=maxSum[i];
        }
    }
    return result;
}