#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

class Solution {
public:
    vector<int> sortJumbled(vector<int>& mapping, vector<int>& nums) {
        vector<int> ans;
        vector<int> priority;
        for(int i=0; i<nums.size(); i++){
            int temp = nums[i];
            int replace = 0;
            int count = 0;
            while(temp/10 != 0){
                replace = replace + mapping[temp%10]*pow(10,count);
                count++;
                temp /= 10;
            }
            replace = replace + mapping[temp%10]*pow(10,count);
            temp = replace;
            cout <<temp;
            bool f = false;
            
            for(int j=0; j<priority.size(); j++){
                if(priority[j] > temp){
                    priority.insert(priority.begin()+j,temp);
                    ans.insert(ans.begin()+j,nums[i]);
                    f = true;
                    break;
                }
            }
            
            if(!f){
                priority.push_back(temp);
                ans.push_back(nums[i]);
            }
        }
        return ans;
    }
};