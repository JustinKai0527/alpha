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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* cur = head;
        int total=0;
        while(cur->next != NULL){
            total++;
            cur = cur->next;
        }
        total++;
        n = (total-n);
        cur = head;
        if(total == 1)    return NULL;
        if(n == 0){                                                    //是head要remove的話
            head = head->next;
            return head;
        }
        while(cur->next != NULL){
            n--;
            if(n == 0){
                cur->next = cur->next->next;
                return head;
            }
            cur = cur->next;
        }                       //因為最後一個一定在最後會解決掉，所以不用在外面重寫一遍
        return head;
    }
};