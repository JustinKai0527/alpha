#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool compare(const int a,const int b){
    return a>b;
}
class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        bool t = true;
        for(int i=nums.size()-1; i>0; i--){
            if(nums[i] > nums[i-1]){
                int temp = nums[i];
                nums[i] = nums[i-1];
                nums[i-1] = temp;
                sort(nums.end()-i,nums.end(),compare);
                t = false;
                break;
            }
        }
        if(t)  sort(nums.begin(),nums.end());
        
    }
};

class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        bool t = true;
        for(int i=nums.size()-1; i>0; i--){
            if(nums[i] > nums[i-1]){
                int temp = nums[i];
                nums[i] = nums[i-1];
                nums[i-1] = temp;
                sort(nums.end()-i,nums.end(),compare);
                t = false;
                break;
            }
        }
        if(t)  sort(nums.begin(),nums.end());
        
    }
};