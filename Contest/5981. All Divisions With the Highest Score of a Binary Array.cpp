#include <iostream>
#include <vector>
using namespace std;


class Solution {
public:
    vector<int> maxScoreIndices(vector<int>& nums) {
        vector<int> ans;
        int Max = score(nums,0);
        int record = 0;
        for(int i=0; i<=nums.size(); i++){
            if(Max < score(nums,i)){
                Max = score(nums,i);
                record = i;
            }
        }
        ans.push_back(record);
        for(int i=record; i<nums.size()-1; i++){
            // if(Max == score(nums,i))    ans.push_back(i);
            if((nums[i]+nums[i+1]) == 1)    ans.push_back(i+2);
            if(nums[i]+nums[i+1] != 1)    break;
        }
        return ans;
    }
    int score(vector<int>& nums, int i){
        int score = 0;
        for(int j=0; j<i; j++){
            if(nums[j] == 0)    score++;
        }
        for(int j=i; j<nums.size(); j++){
            if(nums[j] == 1)    score++;
        }
        return score;
    }
};