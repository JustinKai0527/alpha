#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    void phase(vector<vector<int>>& board){
        int Ysize = board.size();
        int Xsize = board[0].size();

        for(int i=0; i<Ysize; i++){
            for(int j=0; j<Xsize; j++){

                int sum = 0;
                for(int k=0; k<8; k++){
                    int x = j+dir[k].second;
                    int y = i+dir[k].first;
                    
                    if(x>=0 && x<Xsize && y>=0 && y<Ysize){
                        if(board[y][x] == 1)  sum++;
                    }
                }
                
                if(board[i][j] == 1){
                    if(sum<2 || sum>3)  replicate[i][j] = 0;
                    else  replicate[i][j] = 1;
                }
                else if(sum == 3){
                    replicate[i][j] = 1;
                }
            }
        }
        
        board = replicate;
    }
    void gameOfLife(vector<vector<int>>& board) {
        replicate = board;
        phase(board);
    }
private:
    vector<vector<int>> replicate;
    vector<pair<int,int>> dir = {{-1,-1},{-1,0},{-1,1},{0,-1},{0,1},{1,-1},{1,0},{1,1}};
};