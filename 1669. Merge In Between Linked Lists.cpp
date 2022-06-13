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
    ListNode* mergeInBetween(ListNode* list1, int a, int b, ListNode* list2) {
        int count = 0;
        ListNode* cur = list1;
        ListNode* mark_head;
        ListNode* mark_end;
        while(cur->next != NULL){
            if(count == a-1){
                mark_head = cur;
            }
            count++;
            cur = cur->next;
            if(count == b+1){
                mark_end = cur;
            }
        }
        
        mark_head->next = list2;
        cur = list2;
        while(cur->next != NULL){
            cur = cur->next;
        }
        cur->next = mark_end;
        return list1;
    }
};