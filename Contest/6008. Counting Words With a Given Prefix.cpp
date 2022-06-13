#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int prefixCount(vector<string>& words, string pref) {
        int total = 0;

        for(int i=0; i<words.size(); i++){
            if(words[i].size() < pref.size())  continue;
            bool t = true;
            for(int j=0; j<pref.size(); j++){
                if(words[i][j] != pref[j]){
                    t = false;
                    break;
                }
            }
            if(t)  total++;
        }

        return total;
    }
};