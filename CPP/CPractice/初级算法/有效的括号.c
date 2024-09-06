#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <stdbool.h>

char check(char s)
{
    if (s == '(')
        return ')';
    if (s == '{')
        return '}';
    if (s == '[')
        return ']';
    return 0;
}

bool isValid(char *s)
{
    int length = strlen(s);
    if (length % 2 == 1 || length == 0)
        return false;
    char *stack = (int *)malloc(sizeof(int) * length + 1);
    int top = 0;             // 栈顶指针指向栈顶下一个位置
    char needComplete = 't'; // 栈顶左括号需要匹配的右括号
    for (int i = 0; i < length; i++)
    {
        if ((s[i] == '(') || (s[i] == '{') || (s[i] == '['))
        {
            stack[top] = s[i];
            top++;
            needComplete = check(s[i]);
            // printf("%c ",needComplete);
        }
        else
        {
            if (top==0||needComplete != s[i])
                return false;
            else
            {
                top--;                     // 栈顶左括号匹配成功,出栈
                if (top==0){
                    needComplete = 't';//栈空的情况,没有下一个需要匹配的右括号了
                }else{
                    needComplete=check(stack[top-1]);//栈中还有左括号,则更新需要匹配的右括号
                }
                // printf("栈顶:%c 下一个需要匹配:%c ",stack[top],needComplete);
            }
        }
    }
    if (top == 0)
        return true;
    else
        return false;
}