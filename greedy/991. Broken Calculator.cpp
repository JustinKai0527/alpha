#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class Solution {
public:
    int brokenCalc(int startValue, int target) {
        queue<int> q;
        queue<int> temp;
        q.push(startValue);
        int count = 0;

        while(!q.empty()){
            if(q.front() == target)  break;
            if(q.front()*2-1 <= target){ 
                // cout <<q.front()<<endl;
                // cout <<q.front()*2<<endl<<"*&^%^*";
                temp.push(q.front()*2);
            }
            if(q.front()-1 <= target && q.front() > 0){  
                temp.push(q.front()-1);
                // cout <<q.front()-1;
            }
            q.pop();
            if(q.empty()){
                q = temp;
                count++;
                queue<int> replace;
                temp = replace;
            }  
        }

        return count;
    }
};


class Soution {                                             // greedy strategy
public:
    int brokenCalc(int startValue, int target) {
        
    }
};