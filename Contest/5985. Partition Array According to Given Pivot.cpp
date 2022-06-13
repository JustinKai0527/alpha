#include <iostream>
#include <queue>
using namespace std;
class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {
        vector<int> ans;
        queue<int> small;
        queue<int> big;
        int num_of_pivot = 0;
        for(int i=0; i<nums.size(); i++){
            if(nums[i] < pivot){
                small.push(nums[i]);
            }
            else if(nums[i] > pivot){
                big.push(nums[i]);
            }
            else if(nums[i] == pivot){
                num_of_pivot++;
            }
        }
        while(small.empty()){
            ans.push_back(small.front());
            small.pop();
        }
        while(num_of_pivot != 0){
            ans.push_back(pivot);
            num_of_pivot--;
        }
        while(big.empty()){
            ans.push_back(big.front());
            big.pop();
        }
        return ans;
    }
};