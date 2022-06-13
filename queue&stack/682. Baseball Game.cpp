#include <iostream>
#include <vector>
#include <stack>
#include <cstdlib>

using namespace std;

class Solution {
public:
    int calPoints(vector<string>& ops) {
        stack<int> s;

        for(auto i: ops){

            if(i == "C")  s.pop();
            else if(i == "D")  s.push(s.top()*2);
            else if(i == "+"){
                int temp = s.top();
                s.pop();
                int temp2 = s.top();
                s.push(temp);
                s.push(temp + temp2);
            }
            else{
                int temp = stoi(i);
                s.push(temp);
            }
        }

        int sum = 0;
        while(!s.empty()){
            sum+=s.top();
            s.pop();
        }
        return sum;
    }
};