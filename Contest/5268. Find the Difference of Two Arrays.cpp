#include <unordered_set>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> findDifference(vector<int>& nums1, vector<int>& nums2) {
        int size1 = nums1.size();
        int size2 = nums2.size();
        unordered_set<int> hashmap;
        unordered_set<int> hashmap2;
        vector<vector<int>> ans;
        vector<int> n1;
        vector<int> n2;
        for(int i=0; i<size1; i++){
            hashmap.insert(nums1[i]);
        }
        for(int i=0; i<size2; i++){
            if(hashmap.count(nums2[i]) <= 0){
                n2.push_back(nums2[i]);
                hashmap.insert(nums2[i]);
            }
            hashmap2.insert(nums2[i]);
        }
        for(int i=0; i<size1; i++){
            if(hashmap2.count(nums1[i]) <= 0){
                n1.push_back(nums1[i]);
                hashmap2.insert(nums1[i]);
            }
            // hashmap2.insert(nums2[i]);
        }
        ans.push_back(n1);
        ans.push_back(n2);
        return ans;
    }
};