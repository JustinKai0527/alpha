#include <iostream>
#include <stack>
#include <vector>
#include <algorithm>

using namespace std;
                                //not complete
class Solution {
public:
    int longestValidParentheses(string s) {
        stack<char> st;
        vector<int> arr(1,0);
        int size = s.size();

        for(int i=0; i<size; i++){
            if(s[i] == '(')  st.push(s[i]);
            else if(!st.empty()){
                st.pop();
                arr.back()+=2;
            }
            else{
                arr.push_back(0);
            }
        }
        sort(arr.begin(),arr.end());
        return arr.back();
    }
};
