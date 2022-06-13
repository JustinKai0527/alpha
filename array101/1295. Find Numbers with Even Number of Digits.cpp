#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int findNumbers(vector<int>& nums) {
        int ans = 0;
        for(int i=0; i<nums.size(); i++){
            int count = 1;
            while(nums[i]/10 != 0){
                count++;
                nums[i]/=10;
            }
            if(count%2 == 0)  ans++;
        }
        return ans;
    }
};