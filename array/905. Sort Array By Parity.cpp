#include <iostream>
#include <vector>

using namespace std;

class Solution {                                        //quick_sort
public:
    vector<int> sortArrayByParity(vector<int>& nums) {
        int i=0, j=nums.size()-1;
        while(i<j){
            if(nums[i]%2 == 0)  i++;
            else if(nums[j]%2 == 1)  j--;
            else if(nums[i]%2 == 1 && nums[j]%2 == 0){
                swap(nums[i],nums[j]);
                i++;
                j--;
            } 
        }
        return nums;
    }
};

class Solution {                                        //quick_sort
public:
    vector<int> sortArrayByParity(vector<int>& nums) {
        int i=0, j=nums.size()-1;
        while(i<j){
            if(nums[i]%2 > nums[j]%2){
                swap(nums[i],nums[j]);
            }
            if(nums[i]%2 == 0)  i++;
            if(nums[j]%2 == 1)  j--;
            // cout <<i<<" "<<j;
        }
        return nums;
    }
};


class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& nums) {
        vector<int> odd,even;
        int size = nums.size();
        for(int i=0; i<size; i++){
            if(nums[i]%2 == 1)  odd.push_back(nums[i]);
            else  even.push_back(nums[i]);
        }
        size = odd.size();
        for(int i=0; i<size; i++){
            even.push_back(odd[i]);
        }
        return even;
    }
};

int main(void){
    
    return 0;
}