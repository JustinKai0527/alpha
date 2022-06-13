#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    bool digitCount(string num) {
        unordered_map<int,int> second;
        int size = num.size();
        for(int i=0; i<size; i++){
            second[num[i]-48]++;
        }
        for(int i=0; i<size; i++){
            if(second[i]!=num[i]-48)  return false;
        }
        return true;
    }
};