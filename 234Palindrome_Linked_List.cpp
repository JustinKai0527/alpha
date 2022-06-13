#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    bool isPalindrome(ListNode* head) {
        int count = 0;
        ListNode* cur = head;
        while(cur->next != NULL){
            count++;
            cur = cur->next;
        }
        count++;
        
        ListNode* prev = new ListNode;
        prev->next = NULL;
        ListNode* Next = head->next;
        cur = head;
        bool f = false;
        if(count%2 == 1)    f = true;
        count/=2;
        while(count!=0){
            count--;
            cur->next = prev;
            prev = cur;
            cur = Next;
            Next = cur->next;
        }
        head = cur;
        if(f)    head = head->next;
        while(head != NULL){
            if(head->val != prev->val)    return false;
            head = head->next;
            prev = prev->next;
        }
        return true;

    }
};