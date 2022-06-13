#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    int mostFrequent(vector<int>& nums, int key) {
        unordered_map<int,int> hashmap;
        for(int i=0; i<nums.size()-1; i++){
            if(nums[i] == key){
                hashmap[nums[i+1]]++;
            }
        }                        
        int min = 0;
        int target;
        for(auto it = hashmap.begin(); it != hashmap.end(); it++){
            if(min < it->second){
                target = it->first;
                min = it->second;
            }
        }
        return target;
    }
};