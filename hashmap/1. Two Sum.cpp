#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int> hashmap;
        vector<int> ans;
        for(int i=0; i<nums.size(); i++){
            int temp = target-nums[i];
            if(hashmap.count(temp) > 0){
                return {hashmap[temp],i};
            }
            hashmap.insert({nums[i],i});
        }
        return ans;
    }
};
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int> hashmap;
        for(int i=0; i<nums.size(); i++){
            hashmap[i] = nums[i];
        }
        int temp;
        for(int i=0; i<hashmap.size(); i++){
            temp = target-hashmap[i];
            for(int j=0; j<hashmap.size(); j++){
                if(temp == hashmap[j]){
                    vector<int> ans;
                    ans.push_back(i);
                    ans.push_back(j);
                    return ans;
                }
            }
        }
    }
};
