#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int findFinalValue(vector<int>& nums, int original) {
        while(true){
            bool f = false;
            for(int i=0; i<nums.size(); i++){
                if(original == nums[i]){
                    f = true;
                    original*=2;
                }
            }
            if(!f)    break;
        }
        return original;
    }
};