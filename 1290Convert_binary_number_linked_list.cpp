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
    int getDecimalValue(ListNode* head) {
        ListNode* cur = head;
        int count = 0;
        while(cur->next != NULL){
            count++;
            cur = cur->next;
        }
        count++;
        cur = head;
        while(cur->next != NULL){
            cur->next->val += 2*cur->val;
            cur = cur->next;
        }
        return cur->val;
    }
};
// class Solution {
// public:
//     int getDecimalValue(ListNode* head) {
        
//     }
//     friend ListNode& operator||(ListNode& cur,int a){

//     };
// };