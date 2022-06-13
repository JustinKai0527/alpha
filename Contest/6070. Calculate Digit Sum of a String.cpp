#include<iostream>
#include <vector>

using namespace std;

class Solution {
public:
    string calculate(string a){
        int temp = 0;
        for(int i=0; i<3; i++){
            temp+=(int)a[i]-48;
        }
        return to_string(temp);
    }
    string digitSum(string s, int k) {
        while(s.size() > k){
            int size = s.size();
            string temp;
            int i=0;
            for(i=0; i<size; i+=3){
                temp+=calculate(s.substr(i,i+2));
            }
            for(; i<size; i++){
                temp+=to_string(s[i]-48);
            }
            s = temp;
        }
        return s;
    }
};


class Solution {
public:
    string calculate(string a){
        int temp = 0;
        for(int i=0; i<3; i++){
            temp+=(int)(a[i]-48);
            cout <<temp<<endl;
        }
        return to_string(temp);
    }
    string digitSum(string s, int k) {
        while(s.size() > k){
            int size = s.size();
            string temp = "";
            int i=0;
            for(i=0; i+3<size; i+=4){
                cout <<i<<" ";
                cout <<s.substr(i,i+3)<<" ";
                temp+=calculate(s.substr(i,i+3));
            }
            int special = 0;
            for(; i<size; i++){
                special+=int(s[i]-48);
            }
            temp+=to_string(special);
            s = temp;
        }
        return s;
    }
};