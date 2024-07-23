#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

struct ListNode
{
    int val;
    struct ListNode *next;
};
void deleteNode(struct ListNode *node)
{
    struct ListNode *p;
    p = node->next;       // p是node的下一个结点
    node->val = p->val;   // 把p的值给node
    node->next = p->next; // 把p的指向下一个结点的指针给node
    free(p);
}