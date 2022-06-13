#include <iostream>
#include <vector>
#include <stack>

using namespace std;

class Solution {
public:
    string minimizeResult(string expression) {
        int left, right;
        int size = expression.size();
        string l,r;
        bool f = true;

        for(int i=0; i<size; i++){
            if(expression[i] == '+')  f = false;
            if(f)  l.push_back(expression[i]);
            else{
                r.push_back(expression[i]);
            }
        }
        
        left = stoi(l);
        right = stoi(r);
        int min = left+right;
        int temp;

        while(true){
            
        }
    }
};