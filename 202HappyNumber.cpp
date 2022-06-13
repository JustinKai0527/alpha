#include <iostream>
using namespace std;
class Solution {
public:
    bool isHappy(int n) {
        bool t = false;
        long long int digits = n, x;
        long long int sum;
        while(true){
            while(digits/10 != 0){
                x = digits%10;
                sum += (x*x);
            }
            x = digits;
            sum += (x*x);
            digits = sum;
            if(digits == 1){
                t = true;
                return t;
            }
        }
        return t;
    }
};