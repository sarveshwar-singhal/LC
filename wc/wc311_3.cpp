#include<bits/stdc++.h>
using namespace std;
/**
 * Definition for a binary tree node.
 */

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

    //don't need 2 functions. Can traverse with one function only.
    void traverseDepthInside(TreeNode *left, TreeNode *right, int level){
        //base case
        if(left==NULL && right==NULL){
            return;
        }
        traverseDepthBound(left->left, right->right, level+1);
        traverseDepthInside(left->right, left->left, level+1);
        if(level & 1 == 1){
            swap(left->val, right->val);
        }
        return;
    }

    //traverse extreme left and right and then move little inside
    void traverseDepthBound(TreeNode *left, TreeNode *right, int level){
        if(left==NULL && right==NULL){
            return;
        }
        traverseDepthBound(left->left, right->right, level+1);
        if(level & 1 == 1){
            swap(left->val, right->val);
        }
        if(level != 0){
            traverseDepthBound(left->right, right->left, level+1);   
        }
    }

    TreeNode* reverseOddLevels(TreeNode* root) {
        traverseDepthBound(root, root, 0);
        return root;
    }
};