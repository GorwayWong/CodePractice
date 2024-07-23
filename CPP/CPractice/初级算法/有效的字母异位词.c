#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>

bool isAnagram(char* s, char* t) {
        int vat1[255] = {0};
    int vat2[255] = {0};
    int length=strlen(s);
    if(length!=strlen(t)) return false;
    for (int i = 0; i < length; i++)
    {
        vat1[s[i]]+=1;
        vat2[t[i]]+=1;
    }
    for (int i = 0; i < 255; i++)
    {
        if(vat1[i]!=vat2[i]){
            return false;
        }
    }
    return true;
}