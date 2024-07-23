#include <stdlib.h>
#include <stdio.h>
char *convertToRLE(char *str);
char *countAndSay(int n)
{
    char *res = '1';
    for (int i = 1; i < n; i++)
    {
        res = convertToRLE(res);
    }
    return res;
}

char *convertToRLE(char *str)
{
    char *res = (char*)malloc(sizeof(char)*30);
    memset(res,'\0',30);
    char *pre, *q;
    pre = str;
    int count = 0;
    int current = 0;
    while (*pre != '\0')
    {
        count = 1;//一开始pre计1个
        q=pre+1;//q是pre下一个元素
        while ((*q != '\0') &&(*pre==*q))
        {
            count++;
            q++;
        }
        res[current]= '0' + count;
        res[current+1]=*pre;
        current+=2;
        pre=q;
    }
    return res;
}