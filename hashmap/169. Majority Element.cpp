#include <iostream>
#include <vector>
#include <list>
#include <unordered_set>
using namespace std;

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        unordered_set<int> hashmap;
        for(int i=0; i<nums.size(); i++){
            hashmap.insert(nums[i]);
            if(hashmap.count(nums[i]) > nums.size()/2){
                return nums[i];
            }
        }
        return nums[0];

    }
};



class Solution {
public:
    int majorityElement(vector<int>& nums) {
        vector<int> count;
        vector<int> num;
        num.push_back(nums[0]);
        count.push_back(1);
        for(int i=1; i<nums.size(); i++){
            bool t = true;
            for(int j=num.size()-1; j>=0; j--){
                if(num[j] == nums[i]){
                    // for(int k=0; k<num.size(); k++){
                    //     cout <<i<<"&^*"<<num[k]<<" "<<count[k]<<endl;
                    // }
                    num.push_back(num[j]);
                    // for(int k=0; k<num.size(); k++){
                    //     cout <<num[k]<<"&^%"<<endl;
                    // } 
                    
                    num.erase(num.begin()+j);
                    // for(int k=0; k<num.size(); k++){
                    //     cout <<num[k]<<" "<<count[k]<<endl;
                    // } 
                    count.push_back(count[j]+1);
                    // cout <<count.back();
                    count.erase(count.begin()+j);
                    // cout <<count.back()<<endl;
                    // for(int k=0; k<num.size(); k++){
                        // cout <<num[k]<<" "<<count[k]<<endl;
                    // }       
                    t = false;
                    // cout <<num.back()<<count.back();
                    if(count.back() > nums.size()/2)  return num.back();
                }
            }
            if(t){
                num.push_back(nums[i]);
                count.push_back(1);
            }
        }
        return num.back();
    }
};


