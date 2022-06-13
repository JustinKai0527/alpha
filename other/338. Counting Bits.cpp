#include <iostream>
#include <queue> 
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> ans;
        queue<int> temp;
        queue<int> q;
        q.push(1);
        int count = 0;
        if(n == 1)  return {0,1};
        else if(n == 0)  return {0};
        while(count != n+1){
            queue<int> replace;
            while(!q.empty()){
                ans.push_back(q.front());
                temp.push(q.front()+1);
                replace.push(q.front());
                q.pop();
                count++;
                if(count == n+1)  return ans;
            }
            while(!temp.empty()){
                ans.push_back(temp.front());
                replace.push(temp.front());
                temp.pop();
                count++;
                if(count == n+1)  return ans;
            }
            q = replace;
        }

        return ans;
    }
};