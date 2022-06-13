#include <iostream>
#include <unordered_map>
#include <vector>
#include <algorithm>
#include <unordered_set>
using namespace std;

class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        sort(nums1.begin(),nums1.end());
        sort(nums2.begin(),nums2.end());
        if(nums2.back() < nums1.back()){
            vector<int> temp = nums2;
            nums2 = nums1;
            nums1 = temp;
        }
        
        vector<int> ans;
        unordered_map<int,int> hashmap;
        unordered_map<int,int> check;
        for(int i=0; i<nums1.size(); i++){
            hashmap[nums1[i]]++;
            // cout <<nums1[i];
            // cout <<hashmap[nums1[i]];
            // cout <<hashmap.count(nums1[i])<<endl;
        }
        
        for(int i=0; i<nums2.size() && nums1.back() >= nums2[i]; i++){
            if(hashmap.count(nums2[i]) > 0 && check[nums2[i]] <= hashmap[nums2[i]]){
                ans.push_back(nums2[i]);
                check[nums2[i]]++;
            }
        }
        
        return ans;
    }
};