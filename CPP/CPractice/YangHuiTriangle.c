#include<stdio.h>
#include<stdlib.h>

int** generate(int numRows, int* returnSize, int** returnColumnSizes) {
    int** result = (int**)malloc(sizeof(int*) * numRows);//最终返回的二维数组结果
    *returnColumnSizes = (int*)malloc(sizeof(int) * numRows);//存储每行的数字个数
    for (int i = 0; i < numRows; i++) {
        result[i] = (int*)malloc(sizeof(int) * (i + 1));//给二维数组的每个元素数组分配空间
        (*returnColumnSizes)[i] = i + 1;
        for (int j = 0; j <= i; j++) {
            if (j == 0 || j == i) {
                result[i][j] = 1;
            } else {
                result[i][j] = result[i - 1][j - 1] + result[i - 1][j];
            }
        }
    }
    *returnSize = numRows;
    return result;
}
