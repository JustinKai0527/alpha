#include <iostream>
#include <unordered_set>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        unordered_set<int> hashmap;
        vector<int> intersect;
        if(nums1.size() < nums2.size()){
            vector<int> temp;
            temp = nums1;
            nums1 = nums2;
            nums2 = temp;
        }
        for(int i=0; i<nums1.size(); i++){
            if(hashmap.count(nums1[i]) == 0){
                hashmap.insert(nums1[i]);
            }
        }
        for(int i=0; i<nums2.size(); i++){
            if(hashmap.count(nums2[i]) >= 1){
                hashmap.erase(nums2[i]);                            //不能重複
                intersect.push_back(nums2[i]);
            }
        }
        return intersect;
    }
};