#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> findKDistantIndices(vector<int>& nums, int key, int k) {
        vector<int> ans;
        vector<int> pos;
        for(int i=0; i<nums.size(); i++){
            if(key == nums[i])  pos.push_back(i);
        }
        for(int i=0; i<nums.size(); i++){
            for(int j=0; j<pos.size(); j++){
                if(abs(i-pos[j]) <= k){
                    ans.push_back(i);
                    break;
                }
            }
        }
        
        return ans;
    }
};