#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

struct TreeNode
{
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

//这个方法有漏洞
int list[1000] = {0};
int length = 0;
void inorderTravel(struct TreeNode *root, int level)
{
    if (root == NULL)
        return;
    if (root->left != NULL)
        inorderTravel(root->left, level + 1);
    list[length] = root->val + level;
    length++;
    if (root->right != NULL)
        inorderTravel(root->right, level + 1);
}

bool checkSymmetricTree(struct TreeNode *root)
{
    // 中序遍历二叉树 如果对称则构成回文字符串
    length = 0;
    inorderTravel(root,0);
    int i = 0;
    if (length == 0)
        return 0;
    for (i; i < length; i++)
    {
        if (list[i] != list[length - 1 - i])
            return false;
    }
    return true;
}