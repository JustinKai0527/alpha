#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<long long> sumOfThree(long long num) {
        long long int consecutive;
        vector<long long> ans;
        if(num%3 == 0){
            ans.push_back(num/3-1);
            ans.push_back(num/3);
            ans.push_back(num/3+1);
        }    
        return ans;
    }
};