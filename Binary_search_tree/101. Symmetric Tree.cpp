#include <iostream>
#include <stack>
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
    bool isSymmetric(TreeNode* root) {
        if(root->left == NULL && root->right == NULL)    return true;
        TreeNode* right_tree = root->right, * left_tree = root->left ;
        return traverse(right_tree,left_tree);
    }
    bool traverse(TreeNode* left, TreeNode* right){
        if(left == NULL && right == NULL)    return true;
        else if(left == NULL)    return false;
        else if(right == NULL)    return false;
        else if(left->val != right->val)    return false;
        return traverse(left->left,right->right) && traverse(left->right,right->left);
    }
};

