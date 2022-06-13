#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> ans;
        int detect = 0;
        for(int i=0; i<nums.size(); i++){
            if(nums[i] >= target){
                detect = i-1;
                break;
            }
            else    detect = i;
        }
        for(int i=0; i<=detect; i++){
            for(int j=i+1; j<=detect; j++){
                if(target == nums[i]+nums[j]){
                    ans.push_back(i+1);
                    ans.push_back(j+1);
                    return ans;
                }
            }
        }
    }
};