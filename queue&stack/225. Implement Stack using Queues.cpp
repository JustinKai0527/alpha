#include <iostream>
#include <deque>
#include <queue>

using namespace std;

class MyStack {
public:
    MyStack() {

    }
    
    void push(int x) {
        int size = q.size();
        q.push(x);
        for(int i=0; i<size; i++){
            q.push(q.front());
            q.pop();
        }
    }
    
    int pop() {
        int Delete = q.front();
        q.pop();
        return Delete;
    }
    
    int top() {
        return q.front();
    }
    
    bool empty() {
        if(q.empty())  return true;
        return false;
    }

private:
    queue<int> q;
};

class MyStack {
public:
    MyStack() {

    }
    
    void push(int x) {
        temp.push(x);
        while(!q.empty()){
            temp.push(q.front());
            q.pop();
        }
        q = temp;
        queue<int> erase;
        temp = erase;
    }
    
    int pop() {
        int Delete = q.front();
        q.pop();
        return Delete;
    }
    
    int top() {
        return q.front();
    }
    
    bool empty() {
        if(q.empty())  return true;
        return false;
    }

private:
    queue<int> q;
    queue<int> temp;
};

class MyStack {
public:
    MyStack() {
        
    }
    
    void push(int x) {
        if(!temp.empty()){
            q = temp;
            queue<int> erase;
            temp = erase;
        }
        q.push(x);
    }
    
    int pop() {
        while(!q.empty()){
            if(q.size() == 1){  
                return q.front();
            }
            else{
                temp.push(q.front());
                q.pop();
            }
        }
    }
    
    int top() {
        if(!temp.empty()){
            q = temp;
            queue<int> erase;
            temp = erase;
        }
        return q.back();
    }
    
    bool empty() {
        if(!temp.empty()){
            q = temp;
            queue<int> erase;
            temp = erase;
        }
        if(q.empty())  return true;
        return false;
    }

private:
    queue<int> q;
    queue<int> temp;
};

class MyStack {
public:
    MyStack() {
        
    }
    
    void push(int x) {
        if(f){
            q = temp;
            queue<int> erase;
            temp = erase;
            false;
        }
        q.push(x);
    }
    
    int pop() {
        while(!q.empty()){
            if(q.size() == 1)  break;
            else{
                temp.push(q.front());
                q.pop();
            }
        }
        f = true;
        return q.back();
    }
    
    int top() {
        if(f){
            q = temp;
            queue<int> erase;
            temp = erase;
            f = false;
        }
        return q.back();
    }
    
    bool empty() {
        if(f){
            q = temp;
            queue<int> erase;
            temp = erase;
            f = false;
        }
        if(q.empty())  return true;
        return false;
    }

private:
    queue<int> q;
    queue<int> temp;
    bool f = false;
};


/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */