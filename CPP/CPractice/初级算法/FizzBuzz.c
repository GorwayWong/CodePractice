#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

char **fizzBuzz(int n, int *returnSize)
{
    char **result = (char **)malloc(sizeof(char *) * n);
    for (int i = 1; i <= n; i++)
    {
        char *temp = (char *)malloc(sizeof(char) * 9);
        if (i % 3 == 0 && i % 5 == 0)
        {
            strcpy(temp, "FizzBuzz");
        }
        else if (i % 3 == 0)
        {
            strcpy(temp, "Fizz");
        }
        else if (i % 5 == 0)
        {
            strcpy(temp, "Buzz");
        }
        else
        {
            sprintf(temp, "%d", i); // 注意strcpy和sprintf的用法
        }
        result[i - 1] = temp;
    }
    *returnSize = n; // 没返回这个会读不到result的值 导致result是空的
    printf("%s", result[0]);
    return result;
}