#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct ListNode
{
    int val;
    struct ListNode *next;
};

struct ListNode *removeNthFromEnd(struct ListNode *head, int n)
{
    // 没有头结点
    struct ListNode *pre, *q;
    if (head->next == NULL && n >= 1)
        return NULL; // 只有一个结点的情况
    pre = q = head;
    for (int i = 0; i < n - 1; i++)
    {
        if (q == NULL)
        {
            return head;
        }
        q = q->next; // q往前移动n-1次,后续当q的下一个结点为null时,p正好指向需要删除的结点
    }
    while (q->next != NULL) // q移动至最后一个结点
    {
        pre = pre->next;
        q = q->next;
    }
    if(pre==head){
        return pre->next;//当需要删除的结点没有前驱结点
    }
    // 删除pre当前指向的结点 用q重新指向p的前驱结点
    q = head;
    while (q->next != pre)//判断条件是q->next->val != pre->val时 如果有重复值则会报错
    {
        q = q->next;
    }
    q->next = pre->next;
    free(pre);
    return head;
}