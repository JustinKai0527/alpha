#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int findClosestNumber(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int interval = RAND_MAX;
        for(auto it: nums){
            if(abs(interval) >= abs(it))  interval = it;
        }
        return interval;
    }
};