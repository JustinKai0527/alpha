#include <iostream>
#include <unordered_map>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

class Frequent{
public:
    Frequent(){};
    int element;
    int fre;
};

bool compare(const Frequent a, const Frequent b){
    return a.fre>b.fre;
}

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        if(k == nums.size())   return nums;
        unordered_map<int,int> hashmap;
        
        for(int i=0; i<nums.size(); i++){
            hashmap[nums[i]]++;
        }
        vector<int> ans;
        int size = hashmap.size();
        vector<Frequent> vec;
        for(auto it = hashmap.begin(); it != hashmap.end(); it++){
            Frequent a;
            a.element = it->first;
            a.fre = it->second;
            vec.push_back(a);
        }
        sort(vec.begin(),vec.end(),compare);
        int count = 0;
        for(auto it = vec.begin(); it != vec.end(); it++){
            if(count == k)  break;
            count++;
            ans.push_back(it->element);
        }
        return ans;
    }
};

int factorial(int x){
    if(x == 2)  return 2;
    return x*(factorial(x-1));
}
