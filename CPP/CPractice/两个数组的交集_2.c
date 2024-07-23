#include <stdlib.h>
#include <stdio.h>

int cmp(const void *_a, const void *_b)
{
    int *a = _a;
    int *b = _b;
    return *a == *b ? 0 : *a > *b ? 1
                                  : -1;
}
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int *intersect(int *nums1, int nums1Size, int *nums2, int nums2Size, int *returnSize)
{
    qsort(nums1, nums1Size, sizeof(int), cmp);
    qsort(nums2, nums2Size, sizeof(int), cmp);
    int *intersection = (int *)malloc(sizeof(int) * fmin(nums1Size, nums2Size));
    int index1 = 0, index2 = 0;
    int *cur = intersection;
    *returnSize = 0;
    while (index1 < nums1Size && index2 < nums2Size)
    {
        if (nums1[index1] == nums2[index2])
        {
            *cur = nums1[index1];
            cur++;
            (*returnSize)++;
            index1++;
            index2++;
        }
        else if (nums1[index1] < nums2[index2])
        {
            index1++;
        }
        else
        {
            index2++;
        }
    }
    return intersection;
}