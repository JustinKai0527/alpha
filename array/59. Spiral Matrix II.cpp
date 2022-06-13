#include <iostream>
#include <vector>

using namespace std;

class Solution {                                                                //100% faster
public:
    void circle(int level, int& num, int size, vector<vector<int>>& matrix){
        for(int i=level; i<size-level-1; i++){
            matrix[level][i] = num++;
        }
        for(int j=level; j<size-level-1; j++){
            matrix[j][size-level-1] = num++;
        }
        for(int i=size-level-1; i>level; i--){
            matrix[size-level-1][i] = num++;
        }
        for(int j=size-level-1; j>level; j--){
            matrix[j][level] = num++;
        }
    }
    vector<vector<int>> generateMatrix(int n) {
        int num = 1;
        vector<vector<int>> matrix(n,vector<int>(n));
        for(int i=0; i<n/2; i++){
            circle(i,num,n,matrix);
        }
        // for(int i=0; i<n; i++){
        //     for(int j=0; j<n; j++){
        //         printf("%3d",matrix[i][j]);
        //     }
        //     cout <<endl;
        // }
        if(n%2 == 1)  matrix[n/2][n/2] = num;
        return matrix;
    }
};


enum direction{
    RIGHT,
    DOWN,
    LEFT,
    UP
};



class Solution {
public:
    void spiral(vector<vector<int>>& matrix, vector<vector<bool>>& check, int size){
        int temp_x = x + dir[index].second;
        int temp_y = y + dir[index].first;
        if(temp_x >= 0 && temp_x < size && temp_y >= 0 && temp_y < size && check[temp_y][temp_x]){
            check[temp_y][temp_x] = false;
            matrix[temp_y][temp_x] = num++;
            x = temp_x;
            y = temp_y;
            f = true;
        } 
        else{
            if(!f)  return;
            f = false;
            index = (index+1)%4;
        }
        spiral(matrix,check,size);
    }
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> matrix(n,vector<int>(n));
        vector<vector<bool>> check(n,vector<bool>(n,true));
        spiral(matrix,check,n);
        return matrix;
    }
private:
    int num = 1;
    int index = 0;
    int x = -1, y = 0;
    bool f = true;
    vector<pair<int,int>> dir = {{0,1},{1,0},{0,-1},{-1,0}};
};


template <class T>

T sum(T a, T b, T c){
    return a+b+c;
}