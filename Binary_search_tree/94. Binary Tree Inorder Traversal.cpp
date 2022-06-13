#include <vector>
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
    vector<int> inorderTraversal(TreeNode* root) {
        In_order(root);
        return ans;
    }
    void In_order(TreeNode* cur){
        if(cur != NULL){
            In_order(cur->left);
            ans.push_back(cur->val);
            In_order(cur->right);
        }
    }
private:
    vector<int> ans;
};