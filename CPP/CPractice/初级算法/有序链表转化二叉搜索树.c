#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct ListNode
{
    int val;
    struct ListNode *next;
};

struct TreeNode
{
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

struct ListNode* getMedian(struct ListNode* left, struct ListNode* right) {
    // 快慢指针获取链表的中间结点
    struct ListNode* fast = left;
    struct ListNode* slow = left;
    while (fast != right && fast->next != right) {
        fast = fast->next;
        fast = fast->next;
        slow = slow->next;
    }
    return slow;
}

struct TreeNode* buildTree(struct ListNode* left, struct ListNode* right) {
    if (left == right) {
        return NULL;
    }
    struct ListNode* mid = getMedian(left, right);
    struct TreeNode* root = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    root->val = mid->val;
    root->left = root->right = NULL;
    root->left = buildTree(left, mid);
    root->right = buildTree(mid->next, right);
    return root;
}

struct TreeNode* sortedListToBST(struct ListNode* head) {
    //采用左开右闭 所以right=NULL 即把最后的NULL也看作一个结点
    return buildTree(head, NULL);
}