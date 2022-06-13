#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    vector<int> New_Line(vector<int>& line){
        if(line.size() == 1)  return line;
        vector<int> new_line;
        int size = line.size();
        for(int i=1; i<size; i++){
            new_line.push_back((line[i-1]+line[i])%10);
        }
        return New_Line(new_line);
    }
    int triangularSum(vector<int>& nums) {
        if(nums.size() == 1)  return nums[0];
        else{
            return New_Line(nums).front();
        }
    }
};