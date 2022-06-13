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
    ListNode* rotateRight(ListNode* head, int k) {
        if(head == NULL)    return head;
        else if(head->next == NULL)    return head;
        ListNode* cur = head;
        int count = 0;
        while(cur->next != NULL){
            count++;
            cur = cur->next;
        }
        count++;
        k%=count;
        if(k == 0)    return head;
        else{
            ListNode* interval;
            ListNode* initial = head;
            cur = head;
            while(cur->next != NULL){
                count--;
                if(count == k){
                    interval = cur->next;
                    cur->next = NULL;
                    break;
                }
                cur = cur->next;
            }
            head = interval;
            cur = head;
            while(cur->next != NULL){
                cur = cur->next;
            }
            cur->next = initial;
        }
        return head;
    }
};