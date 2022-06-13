#include <iostream>
#include <vector>
#include <stack>
using namespace std;
class Solution {
public:
    int minimumSum(int num) {
        for(int i=0; i<4; i++){
            digit.push_back(num%10);
            num /= 10;
        }
        for(int i=0; i<4; i++){
            for(int j=0; j<4; j++){
                if(i==j)    continue;
                for(int k=0; k<4; k++){
                    if(k==i || k==j)    continue;
                    for(int e=0; e<4; e++){
                        if(e==k || e==i || e==j)    continue;
                        new1 = 10*digit[i] +digit[j];
                        new2 = 10*digit[k] +digit[e];
                        if(new1+new2<Min)    Min = new1+new2;
                    }
                }
            }
        }
        return Min;
    }

private:
    vector<int> digit;
    int new1;
    int new2;
    int a=0,b=0;
    int Min = 200;
};