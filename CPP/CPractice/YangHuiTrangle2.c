#include<stdio.h>
#include<stdlib.h>

int* getRow(int rowIndex, int* returnSize) {
    int** result = (int**)malloc(sizeof(int*)*(rowIndex+1));
    for (int i = 0; i <= rowIndex; i++)
    {
        result[i] = (int*)malloc(sizeof(int)*(i+1));
        for (int j = 0; j <= i; j++)
        {
            if(j==0 || j==i){
                result[i][j]=1;
            }
            else{
                result[i][j]=result[i-1][j-1]+result[i-1][j];
            }
        }
    }
    *returnSize = rowIndex+1;
    return result[rowIndex];
}