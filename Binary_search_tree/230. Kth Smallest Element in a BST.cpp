#include <iostream>
#include <vector>
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

class Solution{
public:
    void search(TreeNode* cur, int k){
        if(cur->left != NULL)  search(cur->left,k);
        count++;
        if(k == count){
            // cout <<cur->val<<endl;
            ans = cur->val;
            return;
        }  
        if(cur->right != NULL)  search(cur->right,k);
    }
    int kthSmallest(TreeNode* root, int k) {
        TreeNode* cur = root;
        // int count = 0;
        search(cur,k);
        return ans;
    }
private:
    int ans = 0;
    int count = 0;
};