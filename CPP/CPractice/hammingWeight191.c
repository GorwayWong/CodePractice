#include<stdlib.h>
#include<stdio.h>

int hammingWeight(uint32_t n){
    int res=0;
    for (int i = 0; i < 32; i++)
    {
        if((n&1)==1){
            res++;
        }
        n>>=1;
    }
    return res;
}