#include<iostream>
#include<vector>
using namespace std;

//Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
    int sum;
public:

    void sumNum(TreeNode* root, int val){
        //base case
        if(root==NULL){
            return;
        }
        if(root->left == NULL && root->right == NULL){
            this->sum += val*10 + root->val;
            return;
        }

        //rec case
        sumNum(root->left, val*10 + root->val);
        sumNum(root->right, val*10 + root->val);
    }

    int sumNumbers(TreeNode* root) {
        this->sum = 0;
        sumNum(root, 0);
        return this->sum;
    }
};