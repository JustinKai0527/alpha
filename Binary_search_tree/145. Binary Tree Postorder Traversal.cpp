#include <iostream>
#include <vector>
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
    vector<int> postorderTraversal(TreeNode* root) {
        Post_order(root);
        return ans;
    }
    void Post_order(TreeNode* cur){
        if(cur != NULL){
            Post_order(cur->left);
            Post_order(cur->right);
            ans.push_back(cur->val);
            
        }
    }
private:
    vector<int> ans;
};