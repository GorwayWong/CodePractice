#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

struct ListNode
{
    int val;
    struct ListNode *next;
};

bool isPalindrome(struct ListNode *head)
{
    struct ListNode *temp = (struct ListNode *)malloc(sizeof(struct ListNode));
    temp->next = NULL;
    struct ListNode *p, *q;
    p = head;
    while (p)
    {
        q=(struct ListNode*)malloc(sizeof(struct ListNode));//不能直接把head的结点给temp
        q->val=p->val;
        q->next=temp->next;
        temp->next=q;
        p=p->next;
    }
    p = head;
    q = temp->next; // 不带头结点
    while (p && q)
    {
        if (p->val != q->val)
            return false;
        p = p->next;
        q = q->next;
    }
    return true;
}