#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    long long numberOfWays(string s) {
        int size = s.size();
        int count = 0;
        for(int i=0; i<size; i++){
            for(int j=i+1; j<size; j++){
                for(int k=j+1; k<size; k++){
                    if(s[i] != s[j] && s[j] != s[k])  count;
                }
            }
        }
        return count;
    }
};