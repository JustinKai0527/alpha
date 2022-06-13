#include <iostream>
using namespace std;
class Solution {
public:
    int value(char c){
        if(c == 'I')    return 1;
        else if(c == 'V')       return 5;
        else if(c == 'X')       return 10;
        else if(c == 'L')       return 50;
        else if(c == 'C')       return 100;
        else if(c == 'D')       return 500;
        else if(c == 'M')       return 1000;
    }
    int romanToInt(string s) {
        int sum = 0;
        bool check = false;
        int x1, x2;
        for(int i=0; i<s.size(); i++){
            if(check){
                check = false;
                continue;
            }
            x1 = value(s[i]);
            x2 = value(s[i+1]);
            if(x1>=x2){
                sum += value(s[i]);
                // check = false;
            }
            else{
                sum += (x2-x1);
                check = true;
            }
        }
        return sum;
    }
};
int main(){
    Solution a;
    string c;
    cin>>c;
    cout <<a.romanToInt(c);
    return 0;
}