#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int Max = 0;
        int count = 0;
        for(int i=0; i<nums.size(); i++){
            if(nums[i] == 1)  count++;
            else{
                if(count > Max)  Max = count;
                count = 0;
            }
        }
        return Max;
    }
};