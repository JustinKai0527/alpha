#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int fib(int n) {
        int a = 0;
        int b = 1;
        int count = 0;
        int ans = 0;
        if(n == 1)  return 1;
        n--;
        
        while(n > 0){
            ans = a+b;
            a = b;
            b = ans;
            n--;
        }
        return ans;
    }
};