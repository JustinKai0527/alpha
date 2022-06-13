#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        unordered_set<int> hashmap;
        for(int i=0; i<nums.size(); i++){
            if(hashmap.count(nums[i]) == 0){
                hashmap.insert(nums[i]);
            }
            else if(hashmap.count(nums[i]) >= 1){
                hashmap.erase(nums[i]);
            }
        }
        unordered_set<int> learn;
        for(int i=0; i<nums.size(); i++){
            learn.insert(nums[i]);
            if(learn.count(nums[i]) >= 2){
                cout <<nums[i]<<endl;
            }
        }
        return *hashmap.begin();                        //因為begin() 是pointer 所以要取直
    }
};


int main(void){
    for(int i=0; i<3; i++){
        cout <<i<<endl;
    }
    return 0;
}