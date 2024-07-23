#include<stdlib.h>
#include<stdio.h>

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

int* postorderTraversal(struct TreeNode* root, int* returnSize) {
    int* res=(int*)malloc(sizeof(int)*101);
    *returnSize=0;
    backTravel(root,res,returnSize);
    return res;
}

void backTravel(struct TreeNode* root,int* res,int* returnSize){
    if(root==NULL){return NULL;}
    if(root->left!=NULL){
        backTravel(root->left,res,returnSize);
    }
    if(root->right!=NULL){
        backTravel(root->right,res,returnSize);
    }
    res[*returnSize]=root->val;
    *returnSize++;
}