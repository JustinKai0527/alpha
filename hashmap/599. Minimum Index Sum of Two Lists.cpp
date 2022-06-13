#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    vector<string> findRestaurant(vector<string>& list1, vector<string>& list2) {
        
        unordered_map<string,int> hashmap;
        unordered_map<int,string> possible_ans;
        
        for(int i=0; i<list1.size(); i++){
            hashmap.insert({list1[i],i});
        }

        int min = RAND_MAX;
        vector<string> ans;
        for(int i=0; i<list2.size(); i++){
            if(hashmap.count(list2[i]) > 0){
                if(min > hashmap[list2[i]] + i){
                    ans.clear();
                    ans.push_back(list2[i]);
                    min = hashmap[list2[i]]+i;
                }
                else if(min == hashmap[list2[i]] + i){
                    ans.push_back(list2[i]);
                }
            }
        }

        return ans;
    }
};