#include<stdlib.h>
#include<stdio.h>

struct ListNode {
    int val;
    struct ListNode *next;
};

struct ListNode* removeElements(struct ListNode* head, int val) {
    if(head==NULL){return NULL;}
    struct ListNode* tempHead=malloc(sizeof(struct ListNode));
    struct ListNode* p;
    tempHead->next=head;//原来的链表没有头节点 创建一个头节点方便操作
    p=tempHead;
    //如果p的下一个节点需要删除 则删除 删除后p不动(防止删除后p的下一个节点还需要删除)
    while (p!=NULL&&p->next!=NULL)
    {
        if(p->next->val==val){
            p->next=p->next->next;
        }else{
            p=p->next;
        }
    }
    head=tempHead->next;
    return head;
}