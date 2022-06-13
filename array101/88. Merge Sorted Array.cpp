#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int start = nums1.size()-nums2.size();
        for(int i=0; i<nums2.size(); i++){
            nums1[start+i] = nums2[i];
        }
        sort(nums1.begin(),nums1.end());
    }
};