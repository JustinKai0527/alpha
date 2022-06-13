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
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* cur = head;
        int sum = 0;
        while(cur->next != NULL){
            sum++;
            cur = cur->next;
        }
        sum++;
        int count = 0;
        ListNode* prev = head;
        ListNode* Next = head->next;
        ListNode* connect_head;
        ListNode* special_Node;
        cur = head;
        while(sum>=k){
            if(cur == head){
                while(count<k-1){
                    count++;
                    cur = Next;
                    Next = cur->next;
                    cur->next = prev;
                    prev = cur;
                }
                special_Node = head;
                head->next = Next;
                head = cur;
            }
            else{
                connect_head = Next;
                cur = connect_head;
                prev = cur;
                Next = Next->next;
                count = 0;
                while(count<k-1){
                    count++;
                    cur = Next;
                    Next = Next->next;
                    cur->next = prev;
                    prev = cur;
                }
                special_Node->next = cur;
                special_Node = connect_head;
                connect_head->next = Next;
            }
            sum -= k;
        }
        return head;
    }
};