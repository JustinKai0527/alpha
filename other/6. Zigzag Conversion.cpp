#include <iostream>
#include <vector>

using namespace std;

enum direction{
    DOWN,
    TOP_RIGHT
};

class Solution {
public:
    string convert(string s, int numRows) {
        int size = s.size();
        string ans;
        vector<vector<int>> matrix(size/numRows+1,vector<int>(numRows,0));
        vector<vector<bool>> check(size/numRows+1,vector<bool>(numRows,false));
        int count = 0;
        for(int i=0; i<size/numRows+1; i+=2){
            for(int j=0; j<numRows; j++){
                check[i][j] = true;
                matrix[i][j] = atoi(&s[count]);
                count++;
                if(count == size)  break;
            }
            for(int j=numRows-2; j>=0; j--){
                check[i][j] = true;
                matrix[i][j] = atoi(&s[count]);
                count++;
                if(count == size)  break;
            }
            if(count == size)  break;
        }
        for(int i=0; i<size/numRows+1; i++){
            for(int j=0; j<numRows; j++){
                if(check[i][j])  ans.push_back(('0'+matrix[i][j]));
            }
        }
        return ans;
    }
};



