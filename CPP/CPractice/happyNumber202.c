#include<stdio.h>
#include<stdlib.h>
#include <stdbool.h>

//运用快慢指针的思想
bool isHappy(int n) {
    int fast=n,slow=n;
    while (true)
    {
        slow=process(slow);
        if(slow==1){
            return true;
        }
        fast=process(fast);
        fast=process(fast);
        if(slow==fast){return false;}
    }
}

int process(int n){
    int res=0;
    while(n!=0){
        res+=(n%10)*(n%10);
        n/=10;
    }
    return res;
}