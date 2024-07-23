#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include<limits.h>

struct TreeNode
{
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

void travelBST(struct TreeNode *root, long long *inorder,int* flag)
{
    if (root->left != NULL)
    {
        travelBST(root->left, inorder,flag);
    }
    if (*inorder >= root->val)//如果遍历到的前一个值大于当前结点的值则不满足二叉搜索树
        *flag = 0;
    printf("%lld %d\n",*inorder,root->val);
    *inorder = root->val;//更新当前遍历到的值为当前结点值
    if (root->right != NULL)
    {
        travelBST(root->right, inorder,flag);
    }
}

bool isValidBST(struct TreeNode *root)
{
    long long *inorder = (long long *)malloc(sizeof(long long));
    *inorder = LLONG_MIN;
    printf("%lld\n", *inorder);
    int *flag = (int*)malloc(sizeof(int));
    *flag=1;
    travelBST(root,inorder,flag);
    printf("---%d---",*flag);
    return *flag;
}

/*
这个写法没考虑右子树的某个结点会小于根结点的情况
*/
// bool isValidBST(struct TreeNode *root)
// {
//     if (root->left != NULL)
//     {
//         if(root->val<=root->left->val) return false;
//         isValidBST(root->left);
//     }
//     if (root->right != NULL)
//     {
//         if(root->val>=root->right->val) return false;
//         isValidBST(root->right);
//     }
//     return true;
// }