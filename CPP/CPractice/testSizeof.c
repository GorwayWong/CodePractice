#include <stdio.h>

int main()
{
    int a;
    a = 6;
    printf("sizeof(double)=%ld\n",sizeof(long double));
    printf("sizeof(a++)=%ld\n",sizeof(a++));
    printf("a=%d\n",a);
    return 0;
}