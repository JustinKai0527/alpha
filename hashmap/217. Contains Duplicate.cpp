#include <iostream>
#include <unordered_set>
#include <vector>
using namespace std;

class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_set<int> check;
        for(int i=0; i<nums.size(); i++){
            if(check.count(nums[i]) <= 0){
                check.insert(nums[i]);
            }
            else  return true;
        }
        return false;
    }
};