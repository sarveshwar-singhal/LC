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

/**
 * @brief check if the given tree is symmetric of not.
 * 
 */
class Solution {
    vector<int> left, right;
public:

    void traverseTreeLeft(TreeNode* root){
        //base case
        if(root==NULL){
            left.push_back(-101);
            return;
        }
        //rec case
        traverseTreeLeft(root->left);
        left.push_back(root->val);
        traverseTreeLeft(root->right);
    }

    void traverseTreeRight(TreeNode* root){
        //base case
        if(root==NULL){
            right.push_back(-101);
            return;
        }
        //rec case
        traverseTreeRight(root->right);
        right.push_back(root->val);
        traverseTreeRight(root->left);
    }

    bool isSymmetric(TreeNode* root) {
        traverseTreeLeft(root->left);
        traverseTreeRight(root->right);

        if(left.size() != right.size()){
            return false;
        }
        for(int i=0;i<left.size();i++){
            if(left[i] != right[i]){
                return false;
            }
        }
        return true;
    }
};

int main(int argc, char const *argv[])
{
    // vector<int> left, right;
    // cout << left.size() << " " << right.size() << endl;
    return 0;
}
