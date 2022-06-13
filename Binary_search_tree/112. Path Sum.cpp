#include <iostream>
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
    bool hasPathSum(TreeNode* root, int targetSum) {
        return check(root,targetSum);
    }
    bool check(TreeNode* cur, int targetSum){
        if(cur == NULL)    return false;
        else if(cur->val == targetSum && cur->right == NULL && cur->left == NULL)    return true;
        targetSum-=cur->val;
        return check(cur->left, targetSum) || check(cur->right, targetSum);
    }
};