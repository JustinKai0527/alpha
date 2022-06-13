#include <iostream>
#include <vector>
#include <stack>
#include <unordered_map>

using namespace std;

class Solution {
public:
    int minDominoRotations(vector<int>& tops, vector<int>& bottoms) {
        unordered_map<int,vector<vector<int>>> hashmap;
        bool f = false;
        int val;
        for(int i=0; i<6; i++){
            hashmap[tops[i]][0].push_back(i);
            hashmap[bottoms[i]][1].push_back(i);
            if(hashmap.count(tops[i]) >= 6 || hashmap.count(bottoms[i]) >=6){
                f = true;
                if(hashmap.count(tops[i]) >= 6)  val = tops[i];
                else val = bottoms[i];
            }
        }
        if(!f)  return -1;

        if(hashmap[val][0].size() <= hashmap[val][1].size())  return hashmap[val][0].size();
        return hashmap[val][1].size();
    }
};



class Solution {
public:
    int minDominoRotations(vector<int>& tops, vector<int>& bottoms) {
        unordered_map<int,int> hashmap;
        int val = 0;
        for(int i=0; i<6; i++){
            hashmap[tops[i]]++;
            hashmap[bottoms[i]]++;
            if(hashmap[tops[i]] >= 6){
                val = tops[i];
                break;
            }      
            else if(hashmap[bottoms[i]] >= 6){
                val = bottoms[i];
                break;
            }  
        }

        int up = 0;
        for(int i=0; i<6; i++){
            if(val == tops[i])  up++;
        }

        if(up>=3)  return 6-up;
        return up;

    }
};