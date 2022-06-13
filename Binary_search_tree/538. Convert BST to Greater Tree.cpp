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

class Solution {                                            //5.5%faster
public:
    void convert(TreeNode* cur,vector<int>& val){
        if(cur->right != NULL)  convert(cur->right,val);
        if(val.empty())  val.push_back(cur->val);
        else{
            cur->val+=val.back();
            val.push_back(cur->val);
        }
        if(cur->left != NULL)  convert(cur->left,val);
    }
    TreeNode* convertBST(TreeNode* root) {
        if(root == NULL)  return NULL;
        vector<int> val;
        TreeNode* cur = root;
        convert(cur,val);
        return root;
    }
};
