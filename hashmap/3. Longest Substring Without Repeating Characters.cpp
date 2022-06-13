#include <iostream>
#include <unordered_map>
#include <vector>
#include <unordered_map>
#include <unordered_set>

using namespace std;


class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int size = s.size();
        int ans = 0;
        unordered_map<char,int> hashmap;

        for(int i=0, j=0; j<size; j++){
            if(hashmap.count(s[j]) > 0){
                i = hashmap[s[j]];
                if(ans < j-i+1)  ans = j-i+1;
                hashmap[s[j]] = j;
                j--;
            }            
            else{
                hashmap[s[j]] = j;
            }
        }
        return ans;
    }
};





int check(string s, int i, int size){                                            //very slow
    int j = i;
    unordered_set<char> map;
    for(j; j<size; j++){
        if(map.count(s[j]) > 0)  break;
        else  map.insert(s[j]);
    }   
    return j-i;
}
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int size = s.size();
        int ans = 0;
        for(int i=0; i<size; i++){
            int temp = check(s,i,size);
            if(ans < temp)  ans = temp;
        }
        return ans;
    }
};

