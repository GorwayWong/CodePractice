#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

bool isValidSudoku(char **board, int boardSize, int *boardColSize)
{
    int *line = (int *)malloc(sizeof(int) * boardSize);
    int *col = (int *)malloc(sizeof(int) * boardSize);
    int *nine = (int *)malloc(sizeof(int) * boardSize);
    int shift = 0;
    for (int i = 0; i < boardSize; i++) {//对数组进行初始化 不然后面的位运算会报错
        line[i] = 0;
        col[i] = 0;
        nine[i] = 0;
    }
    int k;
    for (int i = 0; i < boardSize; i++)
    {
        for (int j = 0; j < boardSize; j++)
        {
            if (board[i][j] == '.')
            {
                continue;
            }
            shift = 1 << (board[i][j] - '1');
            k = (i/3)*3 + j/3;// 计算该元素属于第几个小九宫格
            if((line[i]&shift)>0||(col[j]&shift)>0||(nine[k]&shift)>0){//必须先进行位运算再和0进行比较 运算顺序先后的问题
                return false;
            }
            line[i] |= shift;
            col[j]|=shift;
            nine[k]|=shift;
        }
    }
    return true;
}