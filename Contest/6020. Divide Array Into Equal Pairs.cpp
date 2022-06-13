#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    bool divideArray(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int temp = 0;
        int count = 0;
        for(int i=0; i<nums.size(); i++){
            if(temp != nums[i]){
                if(count%2 != 0)  return false;
                temp = nums[i];
                count = 1;
            }
            else if(temp == nums[i]){
                count++;
            }
        }        

        return true;
    }

};