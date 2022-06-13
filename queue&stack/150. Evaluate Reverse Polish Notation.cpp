#include <iostream>
#include <vector>
#include <stack>
#include <cmath>
using namespace std;

// class Solution {
// public:
//     int evalRPN(vector<string>& tokens) {
//         if(tokens.size() == 1){
//             return String_To_Int(tokens[0]);
//         }
//         stack<string> s;
//         bool t = true;
//         for(int i=0; i<tokens.size(); i++){
//             if((tokens[i] == "+" || tokens[i] == "-" || tokens[i] == "*" || tokens[i] == "/") && t){
//                 ans = String_To_Int(s.top());
//                 s.pop();
//                 t = false;
//             }
//             if(tokens[i] == "+"){
//                 B = String_To_Int(s.top());
//                 s.pop();
//                 ans+=B;
//                 continue;      
//             }
//             else if(tokens[i] == "-"){
                
//                 B = String_To_Int(s.top());
//                 s.pop();
//                 ans = (B-ans);
//                 continue;
//             }
//             else if(tokens[i] == "*"){
//                 B = String_To_Int(s.top());
//                 s.pop();
//                 ans *= B;
//                 continue;
//             }
//             else if(tokens[i] == "/"){
//                 B = String_To_Int(s.top());
//                 s.pop();
//                 ans = (B/ans);
//                 continue;
//             }
//             s.push(tokens[i]);
//         }
//         return ans;
//     }
//     int String_To_Int(string str){
//         int a=0;
//         bool f = false;
//         for(int i=0; i<str.size(); i++){
//             if(str[i] == '-'){
//                 f = true;
//                 continue;
//             }
//             a = 10*a + (str[i] -48);
//         }
//         if(f)    a*=(-1);
//         return a;
//     }
//     string Int_To_String(int a){
//         string str;
//         bool f = false;
//         if(a < 0){
//             a*=(-1);
//             f = true;
//         }
//         while(a != 0){
//             str = (char)(a%10) + str;
//             a /= 10;
//         }
//         if(f)    str = "-"+str;
//         return str;
//     }
// private:
//     int ans;
//     int B;
// };

class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        if(tokens.size() == 1){
            return String_To_Int(tokens[0]);
        }
        stack<string> s;
        bool t = true;
        for(int i=0; i<tokens.size(); i++){
            if(tokens[i] == "+"){
                ans = String_To_Int(s.top());
                s.pop();
                B = String_To_Int(s.top());
                s.pop();
                ans+=B;
                s.push(Int_To_String(ans));
                continue;      
            }
            else if(tokens[i] == "-"){
                ans = String_To_Int(s.top());
                s.pop();
                B = String_To_Int(s.top());
                s.pop();
                ans = B - ans;
                s.push(Int_To_String(ans));
                continue;
            }
            else if(tokens[i] == "*"){
                ans = String_To_Int(s.top());
                s.pop();
                B = String_To_Int(s.top());
                s.pop();
                ans *= B;
                s.push(Int_To_String(ans));
                continue;
            }
            else if(tokens[i] == "/"){
                ans = String_To_Int(s.top());
                s.pop();
                B = String_To_Int(s.top());
                s.pop();
                ans = (B/ans);
                s.push(Int_To_String(ans));
                continue;
            }
            s.push(tokens[i]);
        }
        return String_To_Int(s.top());
    }
    int String_To_Int(string str){
        int a=0;
        bool f = false;
        for(int i=0; i<str.size(); i++){
            if(str[i] == '-'){
                f = true;
                continue;
            }
            a = 10*a + (str[i] -48);
        }
        if(f)    a*=(-1);
        return a;
    }
    string Int_To_String(int a){
        string str = "";
        bool f = false;
        if(a < 0){
            a*=(-1);
            f = true;
        }
        while(a != 0){
            str = (char)((a%10)+48) + str;
            a /= 10;
        }
        if(f)    str = "-"+str;
        return str;
        }
private:
    int ans;
    int B;
};