#include <iostream>
#include <vector>
#include <queue>
using namespace std;



class Solution {
public:
    void reverse(vector<char>& s, vector<char>& ans){
        if(s.empty())    return;
        ans.push_back(s.back());
        s.pop_back();
        reverse(s,ans);
    }
    void reverseString(vector<char>& s) {
        vector<char> ans;
        reverse(s,ans);
        s = ans;
    }
};