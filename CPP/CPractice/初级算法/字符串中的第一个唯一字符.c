#include <stdlib.h>
#include <stdio.h>

int firstUniqChar(char *s)
{
    int vat[255]={0};
    int length = strlen(s);
    for (int i = 0; i < length; i++)
    {
        vat[s[i]]+=1;
    }
    for (int i = 0; i < length; i++)
    {
        if(vat[s[i]]==1){
            return i;
        }
    }
    return -1;
}