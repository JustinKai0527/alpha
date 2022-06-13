#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int percentageLetter(string s, char letter) {
        int size = s.size();
        int count = 0;
        float f;
        for(int i=0; i<size; i++){
            if(s[i] == letter)  count++;
        }

        float f = float(count/size);
        f*=100;
        return (int)f;
    }
};

//complete