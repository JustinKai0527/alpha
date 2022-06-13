#include <iostream>
#include <stack>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

class FreqStack {
public:
    FreqStack() {}
    
    void push(int val) {
        map[val]++;
        hashmap[map[val]].push(val);
        if(freq <= map[val])  freq = map[val];
        // cout <<map[val]<<" " <<hashmap[map[val]].top()<<" " <<freq<<endl;
    }
    
    int pop() {
        int temp = hashmap[freq].top();
        hashmap[freq].pop();
        if(hashmap[freq].empty()){                      //if(hashmap.count(freq) <= 0)  freq--;    why cannot use?
            freq--;
        }
        map[temp]--;
        return temp;
    }

private:
    int freq = 0;
    unordered_map<int,int> map;                         //val,number_of_val
    unordered_map<int,stack<int>> hashmap;              //freq,stack_of_val
};
/**
 * Your FreqStack object will be instantiated and called as such:
 * FreqStack* obj = new FreqStack();
 * obj->push(val);
 * int param_2 = obj->pop();
 */