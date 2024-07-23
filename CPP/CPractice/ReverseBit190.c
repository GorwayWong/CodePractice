#include<stdlib.h>
#include<stdio.h>

uint32_t reverseBits(uint32_t n) {
    uint32_t rev = 0;
    for (int i = 0; i < 32 && n > 0; ++i) {
        rev |= (n & 1) << (31 - i);
        n >>= 1;
    }
    return rev;
}
//在每次循环中，通过(n & 1)获取n的最低位，然后将其左移31 - i位，最后使用|=操作符将计算出的结果与rev进行按位或操作，
//实现将n的最低位加入到rev中。然后将n向右移动一位，继续处理下一位。