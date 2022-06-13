#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        if(nums.size() == 1)  return nums[0];

        sort(nums.begin(),nums.end());
        bool f = false;
        int ans;
        for(int i=0; i<nums.size(); i++){
            if(i == nums.size()-1)  ans = nums[i];
            else if(nums[i] == nums[i+1]){
                i++;
                continue;
            }
            else{
                ans = nums[i];
                break;
            }
        }        
        
        return ans;
    }
};