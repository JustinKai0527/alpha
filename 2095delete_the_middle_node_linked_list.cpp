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
    ListNode* deleteMiddle(ListNode* head) {
        ListNode* cur = head;
        int sum = -1, pos;
        while(cur->next != NULL){
            sum++;
            cur = cur->next;
        }
        sum++;
        if(sum == 0)    return NULL;
        else if(sum%2 == 1)    pos = sum/2 +1;
        else    pos = sum/2;
        cur = head;
        while(cur->next != NULL){
            pos--;
            if(pos == 0){
                cur->next = cur->next->next;
                return head;
            }
            cur = cur->next;
        }
        pos--;
        if(pos == 0){
            cur->next = cur->next->next;
            return head;
        }
        return head;
    }
    void print(ListNode* ans){
        while(ans->next != NULL){
            cout <<ans->val;
            ans = ans->next;
        }
        cout <<ans->val;
    }
};
int main(){
    ListNode a(4);
    ListNode a1(2,&a);
    ListNode list1(1,&a1);
    ListNode b(1);
    ListNode b1(3,&b);
    ListNode list2(1,&b1);
    // ListNode a(1);
    // ListNode a1(2);
    // ListNode list1(1,&a1);
    // // ListNode b(1);
    // ListNode b1(3);
    // ListNode list2(1,&b1);
    Solution c;
    c.print(c.deleteMiddle(&b));
    return 0;
}