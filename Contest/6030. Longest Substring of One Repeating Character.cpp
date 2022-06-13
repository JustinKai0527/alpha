#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> longestRepeating(string s, string queryCharacters, vector<int>& queryIndices) {
        vector<vector<char>> str;
        vector<char> a;
        a.push_back(s[0]);
        for(int i=1; i<s.size(); i++){
            if(a.back() != s[i]){
                str.push_back(a);
                a.clear();
            }
            a.push_back(s[i]);
        }
        for(int i=0; i<queryCharacters.size(); i++){
            
        }
    }
};