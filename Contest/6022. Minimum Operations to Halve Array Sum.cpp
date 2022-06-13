#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

class Solution {
public:
    int halveArray(vector<int>& nums) {
        float sum;
        vector<float> num;
        priority_queue<int> a;
        
        transform(nums.begin(), nums.end(), num.begin(), [](int x) { return (float)x;});
        for(int i=0; i<nums.size(); i++){
            sum+=nums[i];
        }

        float temp = sum;
        int count = 0;
        while(true){
            sort(num.begin(),num.end());
            float d = num.back();
            temp-=d/2;
            count++;
            num.back()/=2;
            if(sum-temp >= sum/2)  return count;
        }
        
        return count;
    }
};