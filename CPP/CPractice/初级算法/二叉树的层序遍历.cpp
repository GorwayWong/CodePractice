#include<vector>
#include<queue>
#include<iostream>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        queue<TreeNode*> nextLevelNodes;//用于存一层的结点
        vector<vector<int>> result;//返回最终结果
        nextLevelNodes.push(root);//根结点入队
        if(root==nullptr) return result;
        while (!nextLevelNodes.empty())
        {
            int currentSize=nextLevelNodes.size();//队列中的结点的子结点没入队前的队列大小
            vector<int> currentLevelNodesValue;//用来存当前层的值
            for (int i = 0; i < currentSize; i++)
            {
                TreeNode* currentNode=nextLevelNodes.front();//取队头结点
                nextLevelNodes.pop();//队头结点出队
                currentLevelNodesValue.push_back(currentNode->val);//队头结点的值放进vector
                if(currentNode->left!=nullptr){
                    nextLevelNodes.push(currentNode->left);//当前结点的左子结点入队
                }
                if(currentNode->right!=nullptr){
                    nextLevelNodes.push(currentNode->right);//当前结点的右子结点入队
                }
            }
            result.push_back(currentLevelNodesValue);
        }
        return result;
    }
};