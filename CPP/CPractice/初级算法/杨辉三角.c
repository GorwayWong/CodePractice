#include <stdlib.h>
#include <stdio.h>
#include <math.h>

int **generate(int numRows, int *returnSize, int **returnColumnSizes)
{
    int **result = (int **)malloc(sizeof(int *) * numRows);    // 作为答案返回的二重数组
    *returnColumnSizes = (int *)malloc(sizeof(int) * numRows); // 每个子数组的长度数组
    for (int i = 0; i < numRows; i++)
    {
        result[i] = (int *)malloc(sizeof(int) * (i + 1)); // 杨辉三角第i行
        returnColumnSizes[0][i] = i + 1;                  // 第i行的长度
        for (int j = 0; j <= i; j++)
        {
            if (j == 0 || j == i)
            {
                result[i][j] = 1;
            }
            else
            {
                result[i][j] = result[i - 1][j - 1] + result[i - 1][j];
            }
        }
    }
    *returnSize = numRows;
    return result;
}