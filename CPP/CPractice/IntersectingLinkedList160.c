#include<stdlib.h>
#include<stdio.h>

struct ListNode {
    int val;
    struct ListNode *next;
};

struct ListNode *getIntersectionNode(struct ListNode *headA, struct ListNode *headB) {
    int length1=0,length2=0;
    struct ListNode* p,*q;
    p=headA;
    while (p!=NULL)
    {       
        p=p->next;
        length1++;
    }
    p=headB;
    while (p!=NULL)
    {
        p=p->next;
        length2++;
    }
    p=headA;
    q=headB;
    int difference = length1>length2 ? length1-length2:length2-length1;
    if(length1>length2){
        for (int i = 0; i < difference; i++)
        {
            p=p->next;
        }
    }else{
        for (int i = 0; i < difference; i++)
        {
            q=q->next;
        }
    }
    while (p!=NULL&&q!=NULL)
    {
        if(p==q){
            return p;
        }
        p=p->next;
        q=q->next;
    }
    return NULL;
}