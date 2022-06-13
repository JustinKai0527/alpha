#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int interval = nums.size()/2;
        int left_boundary = 0;
        int right_boundary = nums.size();
        while(true){
            if(target == nums[interval])  return interval;
            if(right_boundary == left_boundary)  break;
            if(target > nums[interval]){
                left_boundary = interval;
                interval = (left_boundary+right_boundary)/2;
            }
            if(target < nums[interval] ){
                right_boundary = interval;
                interval = (left_boundary+right_boundary)/2;
            }
        }
        return -1;
    }
};


class Solution {
public:
    int search(vector<int>& nums, int target) {
        int left = 0;
        int right = nums.size()-1;
        while(left <= right){
            int pivot = (left+right)/2;
            if(nums[pivot] == target)  return pivot;
            else if(nums[pivot] > target)  right = pivot-1;
            else if(nums[pivot] < target)  left = pivot+1;
            // else if(left == right-1)  break;
        }
        return -1;
    }
};