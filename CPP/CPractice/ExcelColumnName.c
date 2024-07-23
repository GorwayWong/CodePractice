#include<stdio.h>
#include<stdlib.h>

char* convertToTitle(int columnNumber) {
    char* res = (char*)malloc(sizeof(char) * 100);
    char* result = (char*)malloc(sizeof(char) * 100);
    char *p, *q;
    p = res;
    int n;
    int size = 0;
    while (columnNumber != 0) {
        columnNumber--;
        n = columnNumber % 26;
        *p = 'A'+n;
        columnNumber /= 26;
        size++;
        p++;
    }
    *p = '\0';
    q = result;
    for (int i = 0; i < size; i++) {
        p--;
        *q = *p;
        q++;
    }
    *q = '\0';
    free(res);
    return result;
}