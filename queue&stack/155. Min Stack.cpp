#include <iostream>
#include <vector>
using namespace std;

class MinStack {
public:
    MinStack() {
        
    }
    
    void push(int val) {
        if(s.empty())    Min = s[0];
        else if(Min > s.front())    Min = s.front();
        s.push_back(val);
    }
    
    void pop() {
        s.pop_back();
    }
    
    int top() {
        return s.back();
    }
    
    int getMin() {
        return Min;
    }
private:
    vector<int> s;
    int Min;
};