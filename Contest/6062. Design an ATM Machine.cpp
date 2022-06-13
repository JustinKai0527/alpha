#include <iostream>
#include <vector>
#include <stack>

using namespace std;

class ATM {
public:
    ATM() {
        Deposit.resize(5);
        val = {20,50,100,200,500};
    }
    
    void deposit(vector<int> banknotesCount) {
        for(int i=0; i<5; i++){
            Deposit[i]+=banknotesCount[i];
            cout <<Deposit[i]<<" ";
        }
        cout <<endl;
    }
    
    vector<int> withdraw(int amount) {
        vector<int> ans(5);
        vector<int> temp(5);
        for(int i=4; i>=0; i--){
            if(Deposit[i] == 0){
                temp[i] = 0;
                continue;
            }
            if(amount >= val[i]){
                if(amount >= val[i]*Deposit[i]){
                    temp[i] = Deposit[i];
                    amount%=val[i];
                }                
                else{
                    temp[i] = amount/val[i];
                    amount-=(amount/val[i])*Deposit[i];
                }
            }
        }
        if(amount != 0)  return {-1};
        ans = temp;
        for(int i=0; i<5; i++){
            Deposit[i]-=ans[i];
            cout <<Deposit[i]<<" ";
        }
        cout <<endl;
        return ans;
    }
private:
    vector<int> Deposit;
    vector<int> val;
};

/**
 * Your ATM object will be instantiated and called as such:
 * ATM* obj = new ATM();
 * obj->deposit(banknotesCount);
 * vector<int> param_2 = obj->withdraw(amount);
 */