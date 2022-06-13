#include <iostream>
#include <vector>
using namespace std;

class MyCircularQueue {
public:
    MyCircularQueue(int k) {
        ans = new int[k];
        end = ans + (k-1);
    }
    
    bool enQueue(int value) {
        if(head == NULL && tail == NULL){
            head = ans;
            tail = ans;
            ans[0] = value;
            return true;
        }
        else{
            if(head == ans && tail == end)    return false;
            if(tail+1 == head)    return false;
            if(tail == end)    tail = ans;
            else    tail+=1;
            *tail = value;
        }
        return true;
    }
    
    bool deQueue() {
        if(head == NULL && tail == NULL)    return false;
        if(head == tail){
            head = NULL;
            tail = NULL;
        }
        else{
            if(head == end)    head = ans;
            else    head += 1;
        }
        return true;
    }
    
    int Front() {
        if(head == NULL)    return -1;
        return *head;
    }
    
    int Rear() {
        if(tail == NULL)    return -1;
        return *tail;
    }
    
    bool isEmpty() {
        if(tail == NULL && head == NULL)    return true;
        return false;
    }
    
    bool isFull() {
        if(head == NULL && tail == NULL)    return false;
        if(head == ans && tail == end)    return true;
        if(tail == end && ans == head)    return true;
        else if(tail+1 == head)    return true;
        return false;
    }

private:
    int* tail = NULL;
    int* head = NULL;
    int* ans = NULL;  
    int* end = NULL;
};



class MyCircularQueue {                                     //example
private:
    vector<int> data;
    int head;
    int tail;
    int size;
public:
    /** Initialize your data structure here. Set the size of the queue to be k. */
    MyCircularQueue(int k) {
        data.resize(k);
        head = -1;
        tail = -1;
        size = k;
    }
    
    /** Insert an element into the circular queue. Return true if the operation is successful. */
    bool enQueue(int value) {
        if (isFull()) {
            return false;
        }
        if (isEmpty()) {
            head = 0;
        }
        tail = (tail + 1) % size;
        data[tail] = value;
        return true;
    }
    
    /** Delete an element from the circular queue. Return true if the operation is successful. */
    bool deQueue() {
        if (isEmpty()) {
            return false;
        }
        if (head == tail) {
            head = -1;
            tail = -1;
            return true;
        }
        head = (head + 1) % size;
        return true;
    }
    
    /** Get the front item from the queue. */
    int Front() {
        if (isEmpty()) {
            return -1;
        }
        return data[head];
    }
    
    /** Get the last item from the queue. */
    int Rear() {
        if (isEmpty()) {
            return -1;
        }
        return data[tail];
    }
    
    /** Checks whether the circular queue is empty or not. */
    bool isEmpty() {
        return head == -1;
    }
    
    /** Checks whether the circular queue is full or not. */
    bool isFull() {
        return ((tail + 1) % size) == head;
    }
};
