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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode* ans;
        ListNode* curA = headA;
        ListNode* curB = headB;
        int countA = 0;
        while(curA != NULL){
            countA++;
            curA = curA->next;
        }
        
        int countB = 0;
        while(curB != NULL){
            countB++;
            curB = curB->next;
        }
        
        curA = headA;
        curB = headB;
        if(countA > countB){
            while(countA != countB){
                countA--;
                curA = curA->next;
            }
        }
        else{
            while(countB != countA){
                countB--;
                curB = curB->next;
            }
        }

        bool f = false;
        while(curA != NULL){
            if(curA == curB){
                f = true;
                ans = curA;
                break;
            }
            curA = curA->next;
            curB = curB->next;
        }
        return ans;

    }
};