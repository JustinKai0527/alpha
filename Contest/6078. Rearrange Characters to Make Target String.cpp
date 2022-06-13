#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int totalSteps(vector<int>& nums) {
        int count = 0;
        bool f = false;
        int size;
        while(true){    
            f = false;
            size = nums.size();
            for(int i=1; i<size; i++){
                if(nums[i] < nums[i-1]){
                    f = true;
                    nums.erase(nums.begin()+i);
                    i--;
                }
            }
            if(f)  count++;
            else  break;
        }
        return count;
    }
};