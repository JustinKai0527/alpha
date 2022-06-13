#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int convertTime(string current, string correct) {
        int Current = 0, Correct = 0;
        Current = (int)((current[0]-48)*10+current[1]-48)*60+(current[3]-48)*10+current[4]-48;
        Correct = (int)((correct[0]-48)*10+correct[1]-48)*60+(correct[3]-48)*10+correct[4]-48;
        int count = 0;
        int difference = Correct - Current;
        
        if(difference/60 != 0){
            count+=difference/60;
            difference%=60;
        }
        if(difference/10 != 0){
            count+=difference/10;
            difference%=10;
        }
        if(difference/5 != 0){
            count+=difference/5;
            difference%=5;
        }
        if(difference/1 != 0){
            count+=difference/1;
            difference%=1;
        }
        return count;
    }
};