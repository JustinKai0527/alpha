#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int minBitFlips(int start, int goal) {
        string s;
        string g;

        while(start != 0){
            s+=(char)(start%2+48);
            cout <<s<<endl;
        }
        
        while(goal != 0){
            g+=(char)(goal%2+48);
            goal/=2;
        }
        
        int count = 0;
        int S_size = s.size();
        int G_size = g.size();
        if(S_size >= G_size){
            for(int i=S_size-1; i>=0; i--){
                if(i+1 > G_size){
                    if(s[i] == '1')  count++;
                }
                else{
                    if(s[i] != g[i]){
                        count++;
                    }
                }
            }
        }
        else if(S_size < G_size){
            for(int i=G_size-1; i>=0; i--){
                if(i+1 > S_size){
                    if(s[i] == '1')  count++;
                }
                else{
                    if(s[i] != g[i]){
                        count++;
                    }
                }
            }
        }
        return count;
    }
};