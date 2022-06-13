#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        if(stones.size() == 1)  return stones[0];
        priority_queue<int> pq(stones.begin(),stones.end());
        
        while(pq.top() != 0 && pq.size() != 1){
            int temp1 = pq.top();
            pq.pop();
            int temp2 = pq.top();
            pq.pop();

            if(temp1 == temp2)  continue;
            else  pq.push(abs(temp1-temp2));
        }

        return pq.top();
    }
};