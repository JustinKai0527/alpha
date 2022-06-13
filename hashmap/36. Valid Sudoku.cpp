#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>

using namespace std;

class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        
        for(int i=0; i<board.size(); i++){
            unordered_set<char> column;
            unordered_set<char> row;

            for(int j=0; j<board.size(); j++){
                if(board[i][j] != '.'){
                    if(column.count(board[i][j]) <= 0){
                        column.insert(board[i][j]);
                    }
                    else  return false;
                }

                if(board[j][i] != '.'){
                    if(row.count(board[j][i]) <= 0){
                        row.insert(board[j][i]);
                    }
                    else  return false;
                }
            }
        } 

        unordered_map<int,unordered_set<char>> hashmap;
        for(int i=0; i<board.size(); i++){
            for(int j=0; j<board.size(); j++){
                if(board[i][j] == '.')  continue;
                if(hashmap[(i/3)*3+j/3].count(board[i][j]) <= 0){
                    hashmap[(i/3)*3+j/3].insert(board[i][j]);
                }
                else  return  false;
            }
        }
        
        return true;
    }
};




class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        unordered_map<int,unordered_set<char>> hashmap;
        for(int i=0; i<board.size(); i++){
            unordered_set<char> column;
            unordered_set<char> row;

            for(int j=0; j<board.size(); j++){
                if(board[i][j] != '.'){
                    if(column.count(board[i][j]) <= 0){
                        column.insert(board[i][j]);
                    }
                    else  return false;
                }

                if(board[j][i] != '.'){
                    if(row.count(board[j][i]) <= 0){
                        row.insert(board[j][i]);
                    }
                    else  return false;
                }
                
                if(board[i][j] == '.')  continue;
                if(hashmap[(i/3)*3+j/3].count(board[i][j]) <= 0){
                    hashmap[(i/3)*3+j/3].insert(board[i][j]);
                }
                else  return  false;
            }
        } 

        
        return true;
    }
};


class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        unordered_map<int,unordered_set<char>> hashmap;
        for(int i=0; i<board.size(); i++){
            unordered_set<char> column;
            unordered_set<char> row;

            for(int j=0; j<board.size(); j++){
                if(board[i][j] == '.' && board[j][i] == '.')  continue;
                
                if(column.count(board[i][j]) <= 0){
                    column.insert(board[i][j]);
                }
                else  return false;
            
                if(row.count(board[j][i]) <= 0){
                    row.insert(board[j][i]);
                }
                else  return false;
                
                
                if(hashmap[(i/3)*3+j/3].count(board[i][j]) <= 0){
                    hashmap[(i/3)*3+j/3].insert(board[i][j]);
                }
                else  return  false;
            }
        } 

        
        return true;
    }
};