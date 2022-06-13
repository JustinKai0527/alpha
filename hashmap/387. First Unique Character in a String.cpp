#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
public:
    int firstUniqChar(string s) {
        unordered_map<char,int> hashmap;
        for(int i=0; i<s.size(); i++){
            if(hashmap.count(s[i]) <= 0){
                hashmap.insert({s[i],1});
            }
            else{
                hashmap[s[i]]++;
            }
        }
        for(int i=0; i<s.size(); i++){
            if(hashmap[s[i]] == 1)  return i;
        }
        return -1;
    }
};