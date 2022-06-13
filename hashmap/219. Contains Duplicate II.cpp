#include <iostream>
#include <unordered_map>
#include <vector>
#include <unordered_set>

using namespace std;

class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_map<int,vector<int>> hashmap;
        
        for(int i=0; i<nums.size(); i++){
            if(hashmap.count(nums[i]) <= 0){
                hashmap[nums[i]].push_back(i);
            }
            else{
                for(int j=0; j<hashmap[nums[i]].size() ; j++){
                    if( abs(i-hashmap[nums[i]][j]) <= k)    return true; 
                }
                hashmap[nums[i]].push_back(i);
            }
        }

        return false;
    }
};