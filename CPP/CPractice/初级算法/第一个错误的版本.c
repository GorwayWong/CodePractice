#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

// The API isBadVersion is defined for you.
bool isBadVersion(int version);

int firstBadVersion(int n)
{
    int midVersion = n / 2 + 1;
    int left = 1;
    int right = n; // n肯定是坏版本
    int flag;
    if (n == 1)
        return 1;
    while (1)
    {
        flag = isBadVersion(midVersion);
        if ((flag&&(n==1))||(flag && (isBadVersion(midVersion - 1) == false)))
            return midVersion;

        // 左开右闭查找 取中间数
        if (flag)
        { // 如果midVersion是坏版本 且前一个版本也是坏的
            right = midVersion;
            midVersion = (left + right) / 2;
        }
        else
        {// 如果midVersion是好版本 往前折半查找
            left = midVersion + 1;
            midVersion = (left + right) / 2;
        }
    }
}