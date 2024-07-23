#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

struct TreeNode
{
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};
int calculateDepth(struct TreeNode *root)
{
    if (root == NULL)
        return 0;
    int left = calculateDepth(root->left);
    int right = calculateDepth(root->right);
    return left > right ? left+1 : right+1;
}