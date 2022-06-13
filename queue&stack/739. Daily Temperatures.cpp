#include <iostream>
#include <vector>
#include <stack>
using namespace std;

class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        vector<int> ans;
        for(int i=0; i<temperatures.size(); i++){
            for(int j=i+1; j<temperatures.size(); j++){
                if(temperatures[i] < temperatures[j]){
                    ans.push_back(j-i);
                    break;
                }
            }
            if(ans.size() != i+1)    ans.push_back(0);
            
        }
        return ans;
    }
};

class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        stack<int> s;
        int size = temperatures.size();
        vector<int> ans(size,0);

        for(int i=0; i<size; i++){
            if(s.empty())  s.push(temperatures[i]);
            else if(s.top() >= temperatures[i])  s.push(temperatures[i]);
            else{
                while(!s.empty()){
                    
                }
            }
        }
    }
};
