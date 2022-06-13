#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        vector<pair<int,int>> dir = {{-1,0},{0,1},{1,0},{0,-1}};
        vector<vector<bool>> ans;
        queue<pair<int,int>> bfs;
        int length = grid.size();
        int width = grid[0].size();
        int count = 0;
        for(int i=0; i<grid.size(); i++){
            vector<bool> a(grid[i].size());
            for(int j=0; j<grid[i].size(); j++){
                if(grid[i][j] == 1){
                    a[j] = true;
                    count++;
                }
                else  a[j] = false;
                if(grid[i][j] == 2){
                    bfs.push({i,j});
                    // cout <<i<<j<<endl;
                }
            }
            ans.push_back(a);
        }
        // for(int i=0; i<grid.size(); i++){
        //     for(int j=0; j<grid[0].size(); j++){
        //         if(ans[i][j])  cout <<i<<j<<endl;
        //     }
        // }
        int path = 0;
        bool check = false;
        queue<pair<int,int>> temp;
        while(!bfs.empty()){
            for(int i=0; i<dir.size(); i++){
                int x = bfs.front().first + dir[i].first;
                int y = bfs.front().second + dir[i].second;
                // cout <<x<<y<<endl;
                if(x >= 0 && x < width && y >= 0 && y < length && ans[x][y]){
                    ans[x][y] = false;
                    check = true;
                    temp.push({x,y});
                    count--;
                    // cout <<x<<y<<endl;
                }
            }
            bfs.pop();
            if(bfs.empty()){
                bfs = temp;
                if(check)  path++;
                queue<pair<int,int>> replace;
                temp = replace;
                check = false;
            }
        }

        if(count != 0)  return -1;
        return path;
        
    }
};