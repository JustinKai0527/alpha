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
    ListNode* middleNode(ListNode* head) {
        ListNode* cur = head;
        int count = 0;
        while(cur->next != NULL){
            count++;
            cur = cur->next;
        }
        count++;
        count /= 2;
        while(count != 0){
            head = head->next;
            count--;
        }
        return head;
        
    }
};