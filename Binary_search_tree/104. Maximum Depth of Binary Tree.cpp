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
    int maxDepth(TreeNode* root) {
        int depth = 0;
        if(root != NULL){
            depth = traverse(root, depth);
        }
        return depth;
    }
    int traverse(TreeNode* cur, int depth){
        if(cur != NULL){    
            return max(traverse(cur->left, depth+1),traverse(cur->right, depth+1));
        }
        return depth;
    }
};