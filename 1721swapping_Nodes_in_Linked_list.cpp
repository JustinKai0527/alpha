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
        int count(ListNode* head)
    {
        int count = 0;
        
        ListNode* curr = head;
        
        while(curr)
        {
            count++;
            
            curr = curr -> next;
        }
        
        return count;
    }
    
    ListNode* swapNodes(ListNode* head, int k) {
        
        if(head == NULL)
            return NULL;
        
        int n = count(head);
        
        ListNode* start = head;
        
        for(int i = 1; i < k; i++)
        {
            start = start -> next;
        }
        
        ListNode* end = head;
        
        for(int i = 1; i <= n - k; i++)
        {
            end = end -> next;
        }
        
        swap(start -> val, end -> val);      //swap 也可這樣用
        
        return head;
    }
};


class Solution {
public:
    ListNode* swapNodes(ListNode* head, int k) {
        if(head == NULL)    return head;
        else if(head->next == NULL)    return head;
        ListNode* cur = head;
        int total = 0;
        while(cur->next != NULL){
            total++;
            cur = cur->next;
        }
        total++;
        ListNode* left, * right;
        cur = head;
        if(k > total/2)    k = (total - k)+1;               
        if(total == (2*k-1)){                               //只要取一個
            return head;
        }
        else if(k == 1 || k == total){                                    //取首尾
            left = cur;
            head = cur->next;
            left->next = NULL;
            cur = head;
            if(cur->next == NULL){                          //代表只有兩個Node
                head->next = left;
                return head;
            }
            while(cur->next->next != NULL){
                cur = cur->next;
            }
            right = cur->next;
            cur->next = left;
            right->next = head;
            head = right;
        }
        else{                                               //取兩個取中間
            int count = 0;
            while(cur->next != NULL){
                count++;
                if(count == k-1){
                    left = cur->next;
                    cur->next = cur->next->next;
                    left->next = NULL;
                    count++;                                //這邊加加是因為把這個Node移去所以原本有
                }
                if((total-count) == k){                     //不能else原因，因為假如取連續兩個會出事
                    right = cur->next;
                    cur->next = cur->next->next;
                    right->next = NULL;
                    break;
                }
                cur = cur->next;
            }

            count = 0;
            total -= 2;
            cur = head;
            bool t = true;
            while(cur->next != NULL){
                count++;
                if(count == k-1 && t){
                    right->next = cur->next;
                    cur->next = right;                                     
                    count--;                                            //這邊減減是因為把這個Node加進所以原本無
                    t = false;
                }
                if((total-count) == k-1){
                    left->next = cur->next;
                    cur->next = left;
                    break;
                }
                cur = cur->next;
            }
        }
        return head;
    }
};