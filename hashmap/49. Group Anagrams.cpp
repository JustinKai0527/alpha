#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<string> copy = strs;
        for(int i=0; i<copy.size(); i++){
            sort(copy[i].begin(),copy[i].end());
        }
        unordered_map<string,vector<int>> hashmap;
        vector<vector<string>> ans;
        for(int i=0; i<copy.size(); i++){
            hashmap[copy[i]].push_back(i);
        }
        
        for(auto it = hashmap.begin(); it != hashmap.end(); it++){
            vector<string> v;
            for(int i=0; i<(*it).second.size(); i++){
                v.push_back( strs[ (*it).second[i] ] );
            }
            ans.push_back(v);
        }

        return ans;
    }
};