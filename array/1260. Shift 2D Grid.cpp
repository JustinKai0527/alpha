#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {
        if(grid.size() == 1 && grid[0].size() == 1)  return grid;
        vector<int> v;
        int length = grid.size();
        int width = grid[0].size();
        k%=(length*width);
        for(int i=0; i<length; i++){
            for(int j=0; j<width; j++){
                v.push_back(grid[i][j]);
            }
        }      
        vector<int> temp(v.end()-k,v.end());
        v.insert(v.begin(),temp.begin(),temp.end());
        // for(int i=0; i<v.size(); i++){
        //     cout <<v[i]<<" ";
        // }
        v.erase(v.end()-k,v.end());
        for(int i=0; i<length; i++){
            for(int j=0; j<width; j++){
                grid[i][j] = v[i*width+k];
            }
        }     
        return grid;
    }
};


template <class T>

T sum(){

}