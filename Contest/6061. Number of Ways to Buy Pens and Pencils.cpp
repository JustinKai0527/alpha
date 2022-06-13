#include<iostream>
#include <vector>

using namespace std;

class Solution {
public:
    long long waysToBuyPensPencils(int total, int cost1, int cost2) {
        long long num = 0;
        int times = total/cost1+1;
        while(times--){
            int remaining = total - cost1*times;
            num+=(remaining/cost2+1);
        }
        return num;
    }
};