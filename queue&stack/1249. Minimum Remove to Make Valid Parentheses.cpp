#include <iostream>
#include <stack>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    string minRemoveToMakeValid(string s) {
        stack<int> check;
        stack<int> check_2;
        // vector<int> v;
        vector<int> pos;
        int size = s.size()-1;
        for(int i=0; i<s.size(); i++){
            if(s[i] == '('){
                pos.push_back(i);
                check.push(i);
            }
            else if(s[i] == ')' && check.empty()){
                s.erase(s.begin()+i);
                i--;
                // v.push_back(i);
            }
            else if(s[i] == ')'){
                check.pop();
                pos.pop_back();
            }
            
            // if(s[size-i] == ')')  check_2.push(size-i);
            // else if(s[size-i] == '(' && check_2.empty()){
            //     s.erase(s.end()+size-i);
            //     // v.push_back(size-i);
            // }
            // else if(s[size-i] == '(')  check_2.pop();
        }
        for(int i=pos.size()-1; i>=0; i--){
            s.erase(s.begin()+pos[i]);
        }
        // for(int i=0; i<v.size(); i++){
            // s.erase(s.begin()+v[i]);
        // }
        return s;
    }
};


class Solution {                                    //wrong answer
public:
    string minRemoveToMakeValid(string s) {
        stack<int> check;
        stack<int> check_2;
        
        
        for(int i=0; i<s.size(); i++){
            if(s[i] == '(')  check.push(i);
            else if(s[i] == ')' && check.empty()){
                s.erase(s.begin()+i);
                i--;
            }
            else if(s[i] == ')')  check.pop();
        }
        for(int i=s.size()-1; i>=0; i--){
            if(s[i] == ')')  check_2.push(i);
            else if(s[i] == '(' && check_2.empty()){
                s.erase(s.begin()+i);
                i++;
            }
            else if(s[i] == '(')  check_2.pop();
        }
        

        return s;
    }
};