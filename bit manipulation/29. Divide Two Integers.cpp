#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int divide(int dividend, int divisor) {
        long int count = 0;
        bool t = true;
        if(dividend<0)  t = false;
        if(divisor<0&&t)  t = false;
        else  t = true;

        while(dividend>divisor||(dividend<divisor&&!t)){
            if(t)  dividend-=divisor;
            else  dividend+=divisor;
            count++;
        }
        
        if(t)  return count;
        else  return  (-1)*count;
    }
};