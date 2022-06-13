#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
public:
    bool isIsomorphic(string s, string t) {
        unordered_map<char,char> hashmap;
        unordered_map<char,char> check;
        for(int i=0; i<s.size(); i++){
            if(hashmap.count(s[i]) <= 0){
                if(check.count(t[i]) > 0)  return false;
                check.insert({t[i],s[i]});
                hashmap.insert({s[i],t[i]});
                continue;
            }
            if(hashmap[s[i]] != t[i])  return false;
        }   
        return true;   
    }
};