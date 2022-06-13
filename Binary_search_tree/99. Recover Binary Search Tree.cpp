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
 
class Solution {
public:
    void search(TreeNode* cur, vector<int>& ans, vector<TreeNode*>& address){
        if(cur->left != NULL)  search(cur->left,ans,address);
        if(!ans.empty() && cur->val > ans.back())  special = cur;
        ans.push_back(cur->val);
        address.push_back(cur);
        if(cur->right != NULL)  search(cur->right,ans,address);
    }
    void recoverTree(TreeNode* root) {
        TreeNode* cur = root;
        vector<int> ans;
        vector<TreeNode*> address;

        search(cur,ans,address);
        int size = ans.size();
        for(int i=0; i<size; i++){
            if(ans[i] < special->val && ans[i+1] > special->val){
                swap(address[i],special);
            }
        }
        
    }
private:
    TreeNode* special = NULL;
};


class Solution {
public:
    void search(TreeNode* cur, vector<int>& ans, vector<TreeNode*>& address){
        if(cur->left != NULL)  search(cur->left,ans,address);
        ans.push_back(cur->val);
        address.push_back(cur);
        if(cur->right != NULL)  search(cur->right,ans,address);
    }
    void recoverTree(TreeNode* root) {
        TreeNode* cur = root;
        vector<int> ans;
        vector<TreeNode*> address;

        search(cur,ans,address);
        
        int size = ans.size();
        TreeNode* temp1;
        TreeNode* temp2;
        bool t = true;
        for(int i=0; i<size-1; i++){
            if(ans[i] > ans[i+1] && t){
                temp1 = address[i];
                t = false;
            }
            else if(ans[i] > ans[i+1]){
                temp2 = address[i+1];
                break;
            }
        }
        swap(temp1,temp2);
        
    }
private:
    TreeNode* special = NULL;
};