#include <iostream>
#include <stack>
#include <cmath>
using namespace std;

class Solution {
public:
    int reverse(int x) {
        int reverse = 0;
        bool f = false;
        if(x<0){  
            f = true;
            x = -x;
        }
        int count = 0;
        while(x != 0){
            if(reverse*10+x%10 > pow(2,31) - 1)  break;
            reverse = 10*reverse + x%10;
            x/=10;
        }
        int temp = 0;
        while(x != 0){
            temp = 10*temp+x%10;
            x/=10;
            count++;
        }
        if(f)  return -(reverse*pow(10,count)+temp);
        return reverse*pow(10,count)+temp;
    }
};