#include <iostream>
#include <stack>
#include <vector>

using namespace std;

class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        stack<int> s;
        int index = 0;
        for(int i=0; i<pushed.size(); i++){
            s.push(pushed[i]);
            if(popped[index] >= s.top()){
                // cout <<index<<endl;
                while(s.top() == popped[index]){
                    // cout <<"&*()"<<index<<endl;
                    s.pop();
                    index++;
                    if(s.empty())  break;
                }
            }
        }
        if(index != pushed.size())  return false;
        return true;
    }
};