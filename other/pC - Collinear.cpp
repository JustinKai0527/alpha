#include <iostream>
#include <vector>

using namespace std;

int main(){
    int times;
    int num_set;
    cin>>times;
    while(times--){
        cin>>num_set;
        vector<pair<int,int>> point;
        for(int i=0; i<num_set; i++){
            int x,y;
            cin>>x>>y;
            point.push_back({x,y});
        }
        
    }
}

void search(TreeNode* cur, TreeNode* ans, int val){
    if(cur->val == val){
        ans = cur;
    }
    if(cur->left != NULL)  search(cur->left,ans,val);
    if(cur->right != NULL)  search(cur->right,ans,val);
    
}
class Solution {
public:
    TreeNode* searchBST(TreeNode* root, int val) {
        
    }
};