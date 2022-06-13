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
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        TreeNode* head = new TreeNode(nums[nums.size()/2+1]);
        TreeNode* cur = head;
        for(int i=0; i<nums.size()/2+1; i++){
            TreeNode* temp = new TreeNode(nums[i]);
            cur->left = temp;
            cur = temp;
        }
        if(nums.size()>2){
            TreeNode* temp = new TreeNode(nums[nums.size()/2+2]);
            head->right = temp;
            cur = head->right;
            for(int j = nums.size()/2+2; j<nums.size(); j++){
                TreeNode* temp = new TreeNode(nums[j]);
                cur->left = temp;
                cur = temp;
            }
        }
        return head;
    }
};