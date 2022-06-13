#include <iostream>
using namespace std;

class Solution {
public:
    int countEven(int num) {
        int count = 0;
        int digitsum;
        int temp;
        for(int i=1; i<=num; i++){
            digitsum = 0;
            temp = i;
            while(temp/10 != 0){
                digitsum+=(temp)%10;
                temp/=10;
            }
            digitsum+=temp;
            if(digitsum%2 == 0){
                cout <<i<<endl;
                
                count++;
            }
        }
        return count;
    }
};