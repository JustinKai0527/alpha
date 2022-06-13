#include <iostream>
#include <vector>
#include <stack>

using namespace std;

class Solution {
public:
    vector<vector<int>> Max(vector<int>& aliceArrows,int numArrows, int i, int point, vector<vector<int>>& ans){
        if(numArrows == 0 || i >11){
            
        }
    }
    vector<int> maximumBobPoints(int numArrows, vector<int>& aliceArrows) {
        for(int i=0; i<12; i++){
            if(aliceArrows[i] > 0)  aliceArrows[i]*=(-1);
        }
        vector<vector<int>> ans;
        Max(aliceArrows,numArrows,0,0,ans);
    }
};