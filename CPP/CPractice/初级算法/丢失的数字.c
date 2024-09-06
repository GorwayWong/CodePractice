#include<stdlib.h>
#include<stdio.h>
#include<stdbool.h>

int cmp(const void *a,const void *b){//const表示只读 void*表示指针是无类型指针,可以指向任何类型的数据
    return *(int*)a - *(int*)b;//先把指针a强转为(int*)类型的指针 再用*取元素
}

int missingNumber(int* nums, int numsSize) {
    qsort(nums,numsSize,sizeof(nums[0]),cmp);//qsort用快排实现 数组指针 数组大小 每个元素大小 定义的比较元素
    for (int i = 0; i < numsSize; i++)
    {
        if(nums[i]!=i){
            return i;
        }
    }
    return numsSize;
}