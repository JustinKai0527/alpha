#include <iostream>
using namespace std;

class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;
};


class Solution {
public:
    Node* flatten(Node* head) {
        if(head == NULL)   return NULL;
        Node* cur = head;
        Node* mark;
        Node* children;
        Node* mark2;
        bool f = false;
        while(cur->next != NULL || cur->child != NULL){
            if(cur->child != NULL && cur->next == NULL){
                cur->next = cur->child;
                cur->next->prev = cur;
                cur->child = NULL;
                continue;
            }
            if(cur->child != NULL){
                mark = cur;
                cur = cur->child;
                children = cur;
                mark->child = NULL;
                while(cur->next != NULL){
                    if(cur->child != NULL){
                        mark2 = cur;
                        f = true;
                    }
                    cur = cur->next;
                }
                cur->next = mark->next;
                mark->next->prev = cur;
                mark->next = children;
                children->prev = mark;
                if(f)    cur = mark2;
                continue;
            }
            cur = cur->next;
        }
        return head;
    }
};