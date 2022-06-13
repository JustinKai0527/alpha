#include <iostream>
#include <stack>
using namespace std;

class Solution {
public:
    bool isValid(string s) {
        stack<char> input;
        for(int i=0; i<s.size(); i++){
            if(s[i] == '(' || s[i] == '{' || s[i] == '[')    input.push(s[i]);
            else{
                if(input.empty())    return false;              //ex: ']'
                if(s[i] == ')' && input.top() == '(')    input.pop();
                else if(s[i] == ']' && input.top() == '[')    input.pop();
                else if(s[i] == '}' && input.top() == '{')    input.pop();
                else    return false;
            }
        }
        if(input.empty())    return true;
        return false;
    }
};