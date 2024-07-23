#include<stdio.h>
#include<stdlib.h>

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

int* preorderTraversal(struct TreeNode* root,int* returnSize) {
    int* res = (int*)malloc(sizeof(int)*2000);
    *returnSize=0;
    preTravel(root,res,returnSize);
    return res;
}

void preTravel(struct TreeNode* root,int* res,int* returnSize){
    if(root==NULL){
        return;
    }
    res[*returnSize]=root->val;
    *returnSize+=1;
    if(root->left!=NULL){
        preTravel(root->left,res,returnSize);
    }
    if(root->right!=NULL){
        preTravel(root->right,res,returnSize);
    }
}