#ifndef _QUEUE_H_
#define _QUEUE_H_

#include <iostream>

using namespace std;

template <class T>
class Queue{

private:
    T* arr;
    int index;
    int capacity;
};
#endif