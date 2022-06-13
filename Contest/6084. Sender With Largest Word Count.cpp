#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

class Solution {
public:
    string largestWordCount(vector<string>& messages, vector<string>& senders) {
        unordered_map<string,int> map;
        int size = senders.size();
        int count = 0;
        int max;
        string ans;

        for(int i=0; i<size; i++){
            int msn_size = messages[i].size();
            count = 1;

            for(int j=0; j<msn_size; j++){
                if(messages[i][j] == ' ')  count++;
            }
            map[senders[i]]+=count;
            max = map[senders[i]];
            ans = senders[i];
        }
        
        
        for(auto it = map.begin(); it!=map.end(); it++){
            if(max<it->second){
                max = it->second;
                ans = it->first;
            }    
            else if(max == it->second){
                int i=0;
                while(true){
                    if(ans[i]==it->first[i]){
                        i++;
                        continue;
                    }
                    if(ans[i]<it->first[i])  ans = it->first;
                    else  break;
                }
            }
        }
        return ans;
    }
};