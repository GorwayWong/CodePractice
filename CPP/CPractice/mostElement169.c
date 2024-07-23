#include<stdlib.h>
#include<stdio.h>

// 投票法
// 因为多数元素在数组里出现的次数绝对大于n/2，所以用不同元素消去相同元素，剩下的必然是相同元素
int majorityElement(int* nums, int numsSize) {
    int candidate=nums[0];
    int count=0;
    for (int i = 0; i < numsSize; i++)
    {
        if(nums[i]==candidate){
            count++;
        }else{
            count--;
            if(count<0){
                candidate=nums[i];
                count=1;
            }
        }
    }
    return candidate;
}