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
    bool hasCycle(ListNode *head) {
        if(head == NULL)    return false;
        ListNode* cur = head;
        ListNode* prev = new ListNode;
        ListNode* check = prev;
        prev->next = head;
        ListNode* Next = head->next;
        while(cur->next != NULL){
            cur->next = prev;
            prev = cur;
            cur = Next;
            if(Next == check)    return true;
            Next = cur->next;
        }
        return false;
    }
    
};