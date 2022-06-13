#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;



struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};


class Solution {                                        //100% fast
public:
    void search(TreeNode* cur, queue<int>& val){
        if(cur->left != NULL)  search(cur->left,val);
        val.push(cur->val);
        if(cur->right != NULL)  search(cur->right,val);
    }
    TreeNode* create_a_tree(TreeNode* cur, queue<int>& val){
        cur->val = val.front();
        cout <<cur->val<<" ";
        val.pop();
        TreeNode* temp = new TreeNode;
        if(val.empty()){
            cur->right = NULL;
            return cur;
        }
        cur->right = create_a_tree(temp,val);
        return cur;
    }
    TreeNode* increasingBST(TreeNode* root) {
        queue<int> val;
        TreeNode* cur = root;
        search(cur,val);
        cur = new TreeNode;
        root = create_a_tree(cur,val);
        return root;
    }
};


// class Solution {
// public:
//     void search(TreeNode* cur, vector<int>& val){
//         if(cur->left != NULL)  search(cur->left,val);
//         if(cur->right != NULL)  search(cur->right,val);
//         val.push_back(cur->val);
//     }
//     TreeNode* create_a_tree(TreeNode* cur, vector<int>& val){
//         cur->val = val.front();
//         cout <<cur->val<<" ";
//         val.erase(val.begin());
//         TreeNode* temp = new TreeNode;
//         if(val.empty()){
//             cur->right = NULL;
//             return cur;
//         }
//         cur->right = create_a_tree(temp,val);
//         return cur;
//     }
//     TreeNode* increasingBST(TreeNode* root) {
//         vector<int> val;
//         TreeNode* cur = root;
//         search(cur,val);
//         sort(val.begin(),val.end());
//         cur = new TreeNode;
//         root = create_a_tree(cur,val);
//         return root;
//     }
// };