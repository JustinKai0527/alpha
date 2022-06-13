#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

class Solution {
public:
    int maximumBags(vector<int>& capacity, vector<int>& rocks, int additionalRocks) {
        unordered_map<int,int> map;
        int max = 0;
        int size = capacity.size();
        vector<int> record;
        int val;
        for(int i=0; i<size; i++){
            val = abs(capacity[i]-rocks[i]);
            if(val == 0)  max++;
            else if(map.count(val) <= 0){
                map[val] = 1;
                record.push_back(val);
            }
            else{
                map[val]++;
            }
        }
        
        sort(record.begin(),record.end());
        size = record.size();

        for(int i=0; i<size; i++){
            // cout <<map[record[i]]<<endl;
            if(additionalRocks > map[record[i]]*record[i]){
                additionalRocks-=map[record[i]]*record[i];
                max += map[record[i]];
            }
            else if(additionalRocks == map[record[i]]*record[i]){
                max += map[record[i]];
                break;
            }
            else{
                max+=(additionalRocks/record[i]);
                break;
            }
        }
        return max;
    }
};

//complete