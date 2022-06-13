#include <iostream>
#include <vector>
#include <stack>

using namespace std;

class Solution {
public:
    void compute(stack<char>& st, stack<int>& point){
        int count = point.top();
        point.pop();
        st.pop();
        while(!st.empty()){
            if(st.top() == '(')  break;
            else if(st.top() == '#'){
                count+=point.top();
                point.pop();
                st.pop();
            }
        }
        point.push(count*2);
    }
    int scoreOfParentheses(string s) {
        stack<int> point;
        stack<char> st;
        int count = 0;
        st.push('(');
        for(int i=1; i<s.size(); i++){
            if(st.top() == '('){
                st.pop();
            }             
            else if(s[i] == ')' && st.top() == '('){//#(
                st.pop();
                st.push('#');
                point.push(1);
            }
            else if(s[i] == ')' ==  st.top() == '#'){
                compute(st,point);
            }
        }
        int ans = 0;
        while(!point.empty()){
            ans+=point.top();
            point.pop();
        }
        // vector<char> a;
        // while(!st.empty()){
        //     // cout <<st.top();
        //     a.push_back(st.top());
        //     st.pop();
        // }
        // for(int i=a.size()-1; i>=0; i--){
        //     cout <<a[i];
        // }
        // while(true){
            
        // }
        return ans;
    }
};


class Solution {
public:
    void compute(stack<char>& st, stack<int>& point){
        int count = 0;
        while(!st.empty()){
            if(st.top() == '('){  
                st.pop();
                break;
            }
            else{
                st.pop();
                count+=point.top();
                // cout <<count<<endl;
                point.pop();
            }
        }
        
        point.push(count*2);
        st.push('#');
        // cout <<count;
    }
    int scoreOfParentheses(string s) {
        stack<int> point;
        stack<char> st;
        for(int i=0; i<s.size(); i++){
            if(s[i] == '(')  st.push('(');
            else if(s[i] == ')' && st.top() == '('){
                st.pop(); 
                st.push('#');
                point.push(1);
            }
            else if(s[i] == ')' && st.top() == '#'){
                compute(st,point);
            }
            cout <<i<<endl;
            stack<int> temp1 = point;
            stack<char> temp2 = st;
            while(!temp2.empty()){
                cout <<temp2.top();
                temp2.pop();
            }
            cout <<endl;
            while(!temp1.empty()){
                cout <<temp1.top();
                temp1.pop();
            }
            cout <<endl;
        }  
        int ans = 0;
        while(!point.empty()){
            ans+=point.top();
            point.pop();
        }
        return ans;    
    }
};