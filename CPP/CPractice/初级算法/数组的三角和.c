#include<stdlib.h>
#include<stdio.h>
#include<math.h>

int triangularSum(int* nums, int numsSize){
    if(numsSize==1) return nums;
    int*newNums = (int*)malloc(sizeof(int)*(numsSize-1));
    for (int i = 0; i < numsSize-1; i++)
    {
        newNums[i]=nums[i]+nums[i+1];
    }
    return triangularSum(newNums,numsSize-1);
}