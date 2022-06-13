#include <iostream>
#include <vector>
#include <queue> 

using namespace std;

class Solution {
public:
    int BFS(queue<pair<int,int>>& bfs, vector<vector<int>>& grid){
        int end = grid.size()-1;
        int count = 1;
        queue<pair<int,int>> temp;
        bool check[grid.size()][grid.size()];
        for(int i=0; i<grid.size(); i++){
            for(int j=0; j<grid.size(); j++){
                check[i][j] = true;
            }
        }
        while(bfs.front().first != end || bfs.front().second != end){
            if(bfs.front().first  > 0 && bfs.front().second > 0){
                if(grid[bfs.front().first-1][bfs.front().second-1] == 0 && check[bfs.front().first-1][bfs.front().second-1]){
                    temp.push(make_pair(bfs.front().first-1,bfs.front().second-1));
                    check[bfs.front().first-1][bfs.front().second-1] = false;
                }
            }
            if(bfs.front().second > 0){
                if(grid[bfs.front().first][bfs.front().second-1] == 0 && check[bfs.front().first][bfs.front().second-1]){
                    temp.push(make_pair(bfs.front().first,bfs.front().second-1));
                    check[bfs.front().first][bfs.front().second-1] = false;
                }
            }
            if(bfs.front().first  > 0){
                if(grid[bfs.front().first-1][bfs.front().second] == 0 && check[bfs.front().first-1][bfs.front().second]){
                    temp.push(make_pair(bfs.front().first-1,bfs.front().second));
                    check[bfs.front().first-1][bfs.front().second] = false;
                }
            }
            if(bfs.front().first != end && bfs.front().second > 0){
                if(grid[bfs.front().first+1][bfs.front().second-1] == 0 && check[bfs.front().first+1][bfs.front().second-1]){
                    temp.push(make_pair(bfs.front().first+1,bfs.front().second-1));
                    check[bfs.front().first+1][bfs.front().second-1] = false;
                }
            }
            if(bfs.front().first > 0 && bfs.front().second != end){
                if(grid[bfs.front().first-1][bfs.front().second+1] == 0 && check[bfs.front().first-1][bfs.front().second+1]){
                    temp.push(make_pair(bfs.front().first-1,bfs.front().second+1));
                    check[bfs.front().first-1][bfs.front().second+1] = false;
                }
            }
            if(bfs.front().first != end){
                if(grid[bfs.front().first+1][bfs.front().second] == 0 && check[bfs.front().first+1][bfs.front().second]){
                    temp.push(make_pair(bfs.front().first+1,bfs.front().second));
                    check[bfs.front().first+1][bfs.front().second] = false;
                }
                if(bfs.front().second != end && check[bfs.front().first+1][bfs.front().second+1]){   
                    if(grid[bfs.front().first+1][bfs.front().second+1] == 0){
                        temp.push(make_pair(bfs.front().first+1,bfs.front().second+1));
                        check[bfs.front().first+1][bfs.front().second+1] = false;
                    }
                }
            }
            if(bfs.front().second != end){
                if(grid[bfs.front().first][bfs.front().second+1] == 0 && check[bfs.front().first][bfs.front().second+1]){
                    temp.push(make_pair(bfs.front().first,bfs.front().second+1));
                    check[bfs.front().first][bfs.front().second+1] = false;
                }
            }
            
            bfs.pop();
            if(bfs.empty() && temp.empty())  return -1;
            if(bfs.empty()){
                count++;
                bfs = temp;
                // while(!temp.empty()){
                //     cout <<temp.front().first<<" "<<temp.front().second;
                //     cout <<"    ";
                //     temp.pop();
                // }
                // cout <<endl<<count;
                // cout <<endl;
                queue<pair<int,int>> replace;
                temp = replace;
            } 
        } 
        return count;
    }
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        if(grid[0][0] == 1)  return -1;
        queue<pair<int,int>> bfs;
        bfs.push({0,0});
        
        return BFS(bfs,grid);
    }
};