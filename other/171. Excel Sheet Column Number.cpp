#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int titleToNumber(string columnTitle) {
        int total = 0; 
        for(int i=0; i<columnTitle.size(); i++){
            total *= 26;
            total += (int)(columnTitle[i]-96);
        }
        return total;
    }
};