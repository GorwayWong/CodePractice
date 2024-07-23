#include <stdlib.h>
#include <stdio.h>

void rotate(int *nums, int numsSize, int k)
{
    int temp;
    int lastCur; // 暂存被替换的元素的值
    if (nums == NULL || numsSize == 1)
    {
        return;
    }
    int i = 0;
    int cur = 0; // 当前需要移动的元素
    lastCur = nums[0];
    int visited[100] = {0};
    while (i < numsSize)
    {
        if (visited[cur] == 0)
        {
            visited[cur]=1;//防止打转
            temp = nums[(cur + k) % numsSize];
            nums[(cur + k) % numsSize] = lastCur; // 移动元素
            lastCur = temp;
            cur = (cur + k) % numsSize; // 下一个需要移动的元素就是上一次被顶替的元素 它的值暂存在lastCur
        }else{
            cur=(cur+1)%numsSize;
            
            i--;
        }
        i++;
    }
}