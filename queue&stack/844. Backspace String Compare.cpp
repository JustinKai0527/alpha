#include <iostream>
#include <algorithm>
#include <stack>

using namespace std;

class Solution {
public:
    bool backspaceCompare(string s, string t) {
        stack<char> S;
        stack<char> T;
        int size = s.size();

        for(int i=0; i<size; i++){
            
            if(s[i] != '#')  S.push(s[i]);
            else if(!S.empty()){  S.pop();}
        }
        
        size = t.size();
        for(int i=0; i<size; i++){

            if(t[i] != '#')  T.push(t[i]);
            else if(!T.empty()){ 
                cout<<T.top();
                T.pop();
            }
        }

        while(!S.empty() || !T.empty()){

            if(S.empty())  return false;
            if(T.empty())  return false;
            if(S.top() != T.top())  return false;
            S.pop();
            T.pop();
        }
        return true;
    }
};