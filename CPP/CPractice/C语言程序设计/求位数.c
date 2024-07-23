#include <stdio.h>
int main(void)
{
    int count, number;
    count = 0;
    printf("Enter a number:");
    scanf("%d", &number);
    if (number < 0)
        number = -number;
    do
    {
        number = number / 10;
        count++;
    } while (number != 0);
    //当输入的是0时 while语句会有错误
    // while(number!=0){
    //     number=number/10;
    //     count++;
    // }
    printf("It contains %d digits. \n", count);
    return 0;
}