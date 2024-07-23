#include<stdio.h>
#include<stdlib.h>

int titleToNumber(char* columnTitle) {
    int result=0;
    int size = 0;
    char * p =columnTitle;
    while (p&&*p!='\0')
    {
        size++;
        p++;
    }
    p=columnTitle;
    while (p&&*p!='\0')
    {
        result+=((*p-'A')+1)*pow(26,size-1);
        p++;
    }
    return result;
}