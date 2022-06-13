#include <iostream>
#include <stack>
#include <vector>

using namespace std;

class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        stack<pair<int,int>> s;
        check = new bool* [grid.size()];
        
        for(int i=0; i<grid.size(); i++){
            check[i] = new bool [grid[i].size()];
            
            for(int j=0; j<grid[i].size(); j++){

                if(grid[i][j] == 1 && s.empty())  s.push({i,j});
                if(grid[i][j] == 1)  check[i][j] = true;
                else check[i][j] = false;  
            }
        }
        // cout <<s.top().first;
        vector<int> dirx = {-1,0,1,0};
        vector<int> diry = {0,1,0,-1};
        int count = 0;
        while(!s.empty()){
            bool t = true;
            for(int i=0; i<4; i++){
                int x = dirx[i]+s.top().second;
                int y = diry[i]+s.top().first;
                if(isValidPath(grid,x,y)){
                    s.push({y,x});
                    t = false;
                }
            }

            if(t)  s.pop();
            if(s.empty()){
                count++;
                for(int i=0; i<grid.size(); i++){
                    for(int j=0; j<grid[0].size(); j++){
                        if(check[i][j])  s.push({i,j});
                    }
                }
            }
        }

        return count;
    }

    bool isValidPath(vector<vector<char>>& grid, int x, int y){
        if(x>=0 && x<grid[0].size() && y>=0 && y<grid.size())  return false;
        if(!check[y][x])  return false;
        return true;  
    }

private:
    bool** check;
};

class UnionFind{
public:
    UnionFind(int size){
        root.resize(size);
        rank.resize(size);
        count = size;
        for(int i=0; i<size; i++){
            root[i] = i;
            rank[i] = 1;
        }
    }
    int find(int x){
        if(x == root[x])  return x;
        else  return root[x] = find(root[x]);
    }
    void Union(int x, int y){
        int rootx = find(x);
        int rooty = find(y);
        if(rootx != rooty){
            if(rank[rootx] > rank[rooty]){
                root[rooty] = rootx;
            }
            else if(rank[rootx] < rank[rooty]){
                root[rootx] = rooty;
            }
            else{
                rank[rootx]+=1;
                root[rooty] = rootx;
            }
            count--;
        }
    }
    bool isConnected(int x, int y){
        return find(x) == find(y);
    }
    bool num_of_province(char x){
        if(x == '0'){
            count--;
            // cout <<count;
            return false;
        }
        return true;
    }
    int get_count(void){  
        return count;
    }
private:
    vector<int> root;
    vector<int> rank;
    int count = 0;
};

class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int length = grid.size();
        int width = grid[0].size();
        UnionFind Graph(width*length);
        vector<pair<int,int>> dir = {{-1,0},{0,1},{1,0},{0,-1}};

        for(int i=0; i<length; i++){
            for(int j=0; j<width; j++){
                int index = width*i+j;
                // cout <<index<<" ";
                // cout <<grid[i][j]<<" ";
                if(Graph.num_of_province(grid[i][j])){
                    // cout <<"fjsdlkj";
                    for(int k=0; k<4; k++){
                        int x = j + dir[k].second;
                        int y = i + dir[k].first;
                        if(x>=0 && x<width && y>=0 && y<length && grid[y][x]){
                            int temp = y*width+x;
                            if(!Graph.isConnected(index,temp)){
                                Graph.Union(index,temp);
                                cout <<Graph.get_count();
                            }
                        }
                    }            
                }
            }
            // cout <<endl;
        }

        return Graph.get_count();
    }
    
};