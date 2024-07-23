#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

struct ListNode
{
    int val;
    struct ListNode *next;
};

struct ListNode *reverseList(struct ListNode *head)
{
    // 采用头插法
    struct ListNode *res, *p;
    res=(struct ListNode*)malloc(sizeof(struct ListNode)); // 没有这个的话下一个语句会报空指针错误
    res->next = NULL;
    p = head;
    while (head)
    {
        // struct ListNode* temp = (struct ListNode*)malloc(sizeof(struct ListNode));
        p = head->next;
        head->next = res->next;
        res->next = head;
        head = p;
    }
    return res->next; // 不带头结点
}