#include <iostream>
#include <vector>
#include <stack>

using namespace std;

class Solution {
public:
    string removeDuplicates(string s, int k) {
        while(true){
            
            bool t = true;
            int size = s.size();
            int count = 1;
            char check = s[0];
            for(int i=1; i<size; i++){
                if(check != s[i]){
                    check = s[i];
                    count = 1;
                }
                else  count++;
                if(count == k){
                    // cout <<i<<" "<<check<<endl;
                    t = false;
                    s.erase(s.begin()+i-k+1,s.begin()+i+1);
                }
            }
            
            if(t)  break;
        }
        return s;
    }
};