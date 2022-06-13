#include <iostream>
#include <vector>
using namespace std;


class Solution {
public:
    int removeCoveredIntervals(vector<vector<int>>& intervals) {
        for(int i=0; i<intervals.size(); i++){
            bool t = true;
            for(int j=0; j<intervals.size(); j++){
                if(intervals[i][0] <= intervals[j][0] && intervals[i][1] >= intervals[j][1]&& i != j){
                    intervals.erase(intervals.begin()+j);
                    if(i!=0 && t && i > j){
                        i--;
                        t = false;
                    }
                    if(j!=0)  j--;
                    // cout <<i<<j;
                }
            }
            // for(int k=0; k<intervals.size(); k++){
            //     cout <<intervals[k][0] << " " << intervals[k][1]<<endl;
            // }
        }       
        return intervals.size(); 
    }
};



class Solution {
public:
    int removeCoveredIntervals(vector<vector<int>>& intervals) {
        for(int i=0; i<intervals.size(); i++){
            for(int j=0; j<intervals.size(); j++){
                if(intervals[i][0] <= intervals[j][0] && intervals[i][1] >= intervals[j][1]&& i != j){
                    intervals.erase(intervals.begin()+j);
                    if(i!=0)  i--;
                    if(j!=0)  j--;
                    // cout <<i<<j;
                }
            }
        }    
        for(int i=0; i<intervals.size(); i++){
            for(int j=0; j<intervals.size(); j++){
                if(intervals[i][0] <= intervals[j][0] && intervals[i][1] >= intervals[j][1]&& i != j){
                    intervals.erase(intervals.begin()+j);
                    if(i!=0)  i--;
                    if(j!=0)  j--;
                    // cout <<i<<j;
                }
            }
        }    
        return intervals.size(); 
    }
};