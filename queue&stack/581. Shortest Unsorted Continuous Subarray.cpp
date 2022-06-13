#include <iostream>
#include <vector>
#include <stack>

using namespace std;

class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {           //similar to monotomic stack mind ?
        stack<int> s;                                       //I put the no-decreasing nums into stack             
        stack<int> temp;                                    //and check if the next is smaller than the top
        bool f = false;                                     //and then I have to pop to the one which will bigger than the next
        int size = nums.size();                             //but if the delete one is bigger than the following next it will have to think it will become the sorted group 
        int Max = nums[0];                                  //and then I will get the stack size
        s.push(nums[0]);                                    //return Size-stack.size;    
        temp = s;

        for(int i=1; i<size; i++){

            if(!s.empty() && s.top() > nums[i]){
                Max = max(Max,s.top());
                if(f)  s = temp;
                while(!s.empty()){

                    Max = max(Max,s.top());
                    // cout <<Max;
                    if(s.top() > nums[i])  s.pop();
                    else  break;
                }
                temp = s;
                f = true;
            }
            else if(Max > nums[i])  continue;
            else{  
                s.push(nums[i]);
                // cout <<s.top();
                if(!f)  temp = s;
            }
        }
        return size-s.size();
    }   
};


