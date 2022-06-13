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
    ListNode* partition(ListNode* head, int x) {
        if(head == NULL)    return head;
        else if(head->next == NULL)    return head;
        ListNode* cur = head;
        ListNode* end;
        ListNode* stop;
        int total = 0, count = 0;
        while(cur->next != NULL){
            cur = cur->next;
            total++;
        }
        total++;
        end = cur;
        stop = end;
        cur = head;
        ListNode* prev = new ListNode;
        prev->next = head;
        while(cur->next != NULL){
            if(prev == stop)    break;
            else if(count == total)    break;
            if(cur == head && cur->val >= x){
                head = head->next;
                end->next = cur;
                end = end->next;
                cur->next = NULL;
                prev->next = head;
                cur = head;
                continue;
            }
            else if(cur->val >= x && cur->next == NULL)    break;
            else if(cur->val >= x){
                end->next = cur;
                prev->next = cur->next;
                cur->next = NULL;
                end = end->next;
                cur = prev->next;
                continue;
            }
            prev = prev->next;
            cur = prev->next;
            count++;
        }

        return head;
    }
};