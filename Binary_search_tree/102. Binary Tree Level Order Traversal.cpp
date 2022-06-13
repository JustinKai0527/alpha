#include <iostream>
#include <vector>
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



class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {        
        vector<vector<int>> ans;
        if(root == NULL)    return ans;

        queue<TreeNode*> tree;
        queue<TreeNode*> temp_tree;
        tree.push(root);
        int level = 0;
        int num = 1;
        while(num != 0){
            vector<int> temp;
            for(int i=0; i<num; i++){               //進入->pop
                temp.push_back(tree.front()->val);
                temp_tree.push(tree.front());
                tree.pop();
            }
            num = 0;
            while(!temp_tree.empty()){
                if(temp_tree.front()->left != NULL){
                    tree.push(temp_tree.front()->left);
                    num++;
                }
                if(temp_tree.front()->right != NULL){
                    tree.push(temp_tree.front()->right);
                    num++;
                }
                temp_tree.pop();
            }
            ans.push_back(temp);
        }
        return ans;
    }

};
