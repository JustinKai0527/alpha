#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <algorithm>
using namespace std;

class Solution {
public:
    bool change(const int a, const int b){
        return a < b;
    }
    void backtracking(int target){
        
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        
        sort(candidates.begin(),candidates.end(),change);
        
        for(int i=0; i<candidates.size(); i++){
            reg.push_back(candidates[i]);
        }
        level_choices.push_back(reg);
        for(int i=0; i<candidates.size(); i++){
            possible_ans.push_back(candidates[i]);
            backtracking(target);
            possible_ans.clear();
        }
        
        return ans;
    }

private:
    vector<vector<int>> ans;
    vector<vector<int>> level_choices;
    vector<int> possible_ans;
    vector<int> reg;
    int level = 0;
    
};