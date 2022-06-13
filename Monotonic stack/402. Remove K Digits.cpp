#include <iostream>
#include <queue>
#include <stack>
#include <vector>

using namespace std;

class Solution {
public:
    string removeKdigits(string num, int k) {          // monotomic stack   想法:遞增
        if(num.size() == k)  return "0";
        monotomic_stack(num,k);
        if(k != 0){
            num.erase(num.end()-k,num.end());
            cout <<num;
        }
        for(int i=0; i<num.size(); i++){
                        if(num[i] == '0'){
                num.erase(num.begin()+i);
                i--;
            }
            else  break;
        }
        if(num == "")    num = "0";
        return num;
    }
    string monotomic_stack(string& num, int& k){
        bool f = false;
        for(int i=1; i<num.size(); i++){
            if(num[i-1] > num[i]){
                num.erase(num.begin()+i-1);
                k--;
                f = true;
                break;
            }
        }
        if(!f)  return num;
        if(k == 0)  return num;
        return monotomic_stack(num,k);
    }
};

class Solution {
public:
    string removeKdigits(string num, int k) {          // monotomic stack   想法:遞增
        if(num.size() == k)  return "0";
        for(int i=1; i<num.size(); i++){
            if(num[i-1] > num[i]){
                num.erase(num.begin()+i-1);
                k--;
                i--;
            }
            if(k == 0)  break;
        }
        if(k != 0){
            num.erase(num.end()-(k+1),num.end());
        }
        for(int i=0; i<num.size(); i++){
            if(num[i] == '0'){
                num.erase(num.begin()+i);
                i--;
            }
            else  break;
        }
        if(num == "")    num = "0";
        return num;
    }
};