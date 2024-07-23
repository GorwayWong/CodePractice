#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

struct ListNode
{
    int val;
    struct ListNode *next;
};

struct ListNode *mergeTwoLists(struct ListNode *list1, struct ListNode *list2)
{
    struct ListNode *res = (struct ListNode *)malloc(sizeof(struct ListNode));
    res->next = NULL; // 必须手动初始化成员 不然会报错
    struct ListNode *p, *q, *cur;
    p = list1;
    q = list2;
    cur = res;
    while (p && q)
    {
        if (p->val <= q->val)
        {
            cur->next = p;   // 把较小的放到新链表里
            cur = cur->next; // 尾插法 cur指向新链表最后一个元素
            p = p->next;     // p指向list1的下一个需要比较的元素
        }
        else
        {
            cur->next = q;
            cur = cur->next;
            q = q->next;
        }
    }
    if (p)
    {
        cur->next = p;
    }
    if (q)
    {
        cur->next = q;
    }
    return res->next; // 不要头结点
}