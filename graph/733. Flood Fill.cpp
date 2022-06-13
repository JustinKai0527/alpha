#include <iostream>
#include <vector>
#include <stack>


using namespace std;


class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        stack<pair<int,int>> dfs;
        if(image[sr][sc] != newColor)  return image;
        
        dfs.push({sr,sc});
        vector<pair<int,int>> a = {{-1,0},{0,1},{1,0},{0,-1}};
        int color = image[sr][sc];
        
        bool** check = new bool* [image.size()];
        for(int i=0; i<image.size(); i++){
            check[i] = new bool [image[i].size()];
            for(int j=0; j<image[i].size(); j++){
                check[i][j] = true;
            }
        }

        while(!dfs.empty()){
            bool f = false;

            for(int i=0; i<4; i++){
                int y = dfs.top().first+a[i].first;
                int x = dfs.top().second+a[i].second;

                if(x>=0 && x<image[0].size() && y>=0 && y<image.size() && check[y][x] && image[y][x] == color){
                    check[y][x] = false;
                    image[y][x] = newColor;
                    f = true;
                    dfs.push({y,x});
                }
            }

            if(!f)  dfs.pop();
        }

        for(int i=0; i<image.size(); i++){
            delete[] check[i];
        }
        delete[] check;
        
        return image;
    }
};