#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int countHillValley(vector<int>& nums) {
        int count = 0;
        int temp;
        bool f = false;
        for(int i=1; i<nums.size()-1; i++){
            if(nums[i] == nums[i+1]){
                f = true;
                temp = nums[i-1];
            }
            if(f){
                f = false;
                nums[i-1] = temp;
            }
            if(nums[i] > nums[i+1] && nums[i] > nums[i-1])  count++;
            else if(nums[i] < nums[i+1] && nums[i] < nums[i-1])  count++;
        }

        return count;
    }
};