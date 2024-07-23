#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};
//112.路径总和
//根结点到叶子结点的路径
//需要考虑有正有负的情况
bool hasPathSum(struct TreeNode* root, int targetSum) {
    //if(root!=NULL){printf("%d %d\n",root->val,targetSum);}
    if (root==NULL){return false;}
    else if ((root->val == targetSum)&&(root->left==NULL&& root->right==NULL))
    {
        printf("test");
        return true;
    }
    if (root->left!= NULL){
        if (hasPathSum(root->left,targetSum - root->val)){
            return true;
        }
    }
    if (root->right != NULL)
    {
        if (hasPathSum(root->right,targetSum - root->val)){
            return true;
        }
    }
    return false;
}