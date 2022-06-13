#include <vector>
#include <iostream>
using namespace std;


class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        if(nums.empty())  return {};
        vector<string> ans;
        string range;
        string str;
        int start = nums[0];
        int temp = start;
        int end = start;
        if(nums.size() == 1){
            str = to_string(start);
            range += str;
            ans.push_back(range);
            return ans;
        }
        for(int i=1; i<nums.size(); i++){
            if(temp+1 == nums[i]){
                end = nums[i];
                temp = nums[i];
                continue;
            }
            
            str = to_string(start);
            if(start == temp){
                range.clear();
                range += str;
                ans.push_back(range);
                start = nums[i];
                temp = nums[i];
                end = nums[i];
            }
            else{
                range.clear();
                range += str;
                range+="->";
                str = to_string(end);
                range += str;
                ans.push_back(range);
                start = nums[i];
                temp = start;
                end = start;
            }
        }
        
        str = to_string(start);
        if(start == temp){
            range.clear();
            range += str;
            ans.push_back(range);
        }
        else{
            range.clear();
            range += str;
            range+="->";
            str = to_string(end);
            range += str;
            ans.push_back(range);
        }
        return ans;

    }
};