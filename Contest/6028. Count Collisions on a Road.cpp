#include <iostream>
#include <vector>
#include <stack>
#include <queue>

using namespace std;

class Solution {
public:
    int countCollisions(string directions) {
        stack<char> num;
        int sum = 0;
        num.push(directions[0]);
        for(int i=1; i<directions.size(); i++){
            if(num.empty()) num.push(directions[i]);
            if(directions[i] == 'R')  num.push('R');
            else if(directions[i] == 'L' && num.top() == 'R'){
                sum+=2;
                num.pop();
                directions[i] = 'S';
                i--;
                
            }
            else if(directions[i] == 'L' && num.top() == 'L'){}
            else if(directions[i] == 'L' && num.top() == 'S'){
                sum+=1;
                num.pop();
                directions[i] = 'S';
                i--;
                
            }
            else if(directions[i] == 'S' && num.top() == 'R'){
                sum+=1;
                num.pop();
                directions[i] = 'S';
                i--;
            }
            else if(directions[i] == 'S')  num.push('S');
        }
        return sum;
    }
};

class Solution {
public:
    int countCollisions(string directions) {
        stack<char> num;
        int sum = 0;
        num.push(directions[0]);
        for(int i=1; i<directions.size(); i++){
            
        }
        return sum;
    }
};