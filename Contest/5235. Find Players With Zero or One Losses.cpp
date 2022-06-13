#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

class Solution {
public:
    vector<vector<int>> findWinners(vector<vector<int>>& matches) {
        vector<vector<int>> ans;
        vector<int> a;
        vector<int> b;
        unordered_set<int> hashmap;
        unordered_set<int> FALSE;
        unordered_set<int> lose;
        unordered_set<int> losefalse;
        int size = matches.size();
        for(int i=0; i<size; i++){
            if(FALSE.count(matches[0][i]) == 0){
                hashmap.insert(matches[0][i]);
            }
            if(hashmap.count(matches[1][i]) != 0 || FALSE.count(matches[1][i]) != 0){
                hashmap.erase(matches[1][i]);
                FALSE.insert(matches[1][i]);
            }
            
            if(losefalse.count(matches[1][i]) == 0){
                lose.insert(matches[1][i]);
            }
            if(lose.count(matches[1][i]) != 0 || losefalse.count(matches[1][i]) != 0){
                lose.erase(matches[1][i]);
                losefalse.insert(matches[1][i]);
            }
        }
        for(auto it = lose.begin(); it != lose.end(); it++){
            cout <<*it;
        }
        return ans;
        
        
    }
};