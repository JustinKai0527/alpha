#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int size = nums.size();
        int left = 0, right = size-1;

        while(left <= right){
            int mid = left+(right-left)/2;
            int test = nums[mid];

            if(test == target)  return mid;
            else if(test < target){
                left = mid+1;
            }
            else if(test > target){
                if(target < nums[size-1]){
                    left = mid+1;
                }
                else{
                    right = mid-1;
                }
            }
        }

        return -1;
    }
};

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int size = nums.size();
        if(target <= nums[size-1]){
            for(int i=size-1; i>=0; i--){
                if(target == nums[i])  return i;
            }
        }
        else if(target >= nums[0]){
            for(int i=0; i<size; i++){
                if(target == nums[i])  return i;
            }
        }
        return -1;
    }
};


