#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int left = 0, right = matrix.size()-1;
        int length;
        while(left < right){
            int mid = left + (right-left)/2;
            if(matrix[mid][0] > target)  right = mid-1;
            else if(matrix[mid][0] < target)  left = mid;
            else if(matrix[mid][0] == target)  return true;
        }
        
        length = left + (right-left)/2;

        left = 0;
        right = matrix[length].size()-1;
        while(left <= right){
            int mid = left + (right-left)/2;
            if(matrix[length][mid] > target)  right = mid-1;
            else if(matrix[length][mid] < target)  left = mid;
            else if(matrix[length][mid] == target)  return true;
        }

        return false;
    }
};


class Solution {                                                    //88% fast && 50% memory
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int left,right;
        int length = -1;
        for(int i=0; i<matrix.size(); i++){
            if(matrix[i][0] <= target){
                length = i;
            }
        }
        // cout <<length;
        if(length == -1)  return false;
        if(matrix[length].size() == 1){
            if(matrix[length][0] == target)  return true;
            return false;
        }
        left = 0;
        right = matrix[length].size()-1;
        while(left <= right){
            int mid = left + (right-left)/2;
            if(matrix[length][mid] > target)  right = mid-1;
            else if(matrix[length][mid] < target)  left = mid+1;
            else if(matrix[length][mid] == target)  return true;
        }

        return false;
    }
};


