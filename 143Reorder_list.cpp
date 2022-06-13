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
    void reorderList(ListNode* head) {
        if(head->next != NULL){
            ListNode* cur = head;
            int total = 0;
            while(cur->next != NULL){
                total++;
                cur = cur->next;
            }
            total++;

            int count = 0;
            if(total%2 == 1)    count = -1;
            cur = head;
            ListNode* head2;
            while(count != total/2-1){
                count++;
                cur = cur->next;
            }
            head2 = cur->next;
            cur->next = NULL;
            ListNode* prev = head2;
            ListNode* Next = head2->next;
            ListNode* cur2 = head2;
            while(Next != NULL){
                cur2 = Next;
                Next = Next->next;
                cur2->next = prev;
                prev = cur2;
            }
            head2->next = NULL;
            head2 = cur2;

            cur = head;
            count = 0;
            while(count != total/2){
                count++;
                ListNode* temp = cur2->next;
                cur2->next = cur->next;
                cur->next = cur2;
                cur = cur->next->next;
                cur2 = temp;
            }
        }
    }

};