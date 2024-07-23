#include<stdlib.h>
#include<stdio.h>

//留到看dp时候写
int massage(int* nums, int numsSize){
    if(numsSize==1){return nums[0];}
    int start = nums[0]>nums[1]?0:1;
    int result = nums[start];
    for (int i = start+2; i < numsSize; i+=2)
    {
        if(i+1<numsSize&&nums[i+1]>nums[i]){
            result+=nums[i+1];
            i++;
        }else{
            result+=nums[i];
        }
    }
    return result;
}