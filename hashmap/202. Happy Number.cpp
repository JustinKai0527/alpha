#include <iostream>
#include <vector>
#include <unordered_set>
#include <cmath>
using namespace std;

class Solution {
public:
    bool isHappy(int n) {
        int sum = 0;
        unordered_set<int> hashmap;
        while(n != 1){
            if(hashmap.count(n) >= 1)  return false;
            else  hashmap.insert(n);
            while( n/10 != 0 ){
                sum += pow(n%10,2);
                n /= 10;
            }
            sum += pow(n,2);
            n = sum;
            sum = 0;
        }
        return true;
    }
};