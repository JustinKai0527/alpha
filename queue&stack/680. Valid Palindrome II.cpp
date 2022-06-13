#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class Solution {
public:
    bool check(string s,int i){
        int size = s.size();
        for(; i<=size/2; i++){
            if(s[i] == s[size-1-i])  continue;
            else  return false;
        }
        return true;
    }
    bool validPalindrome(string s) {
        int size = s.size();
        for(int i=0; i<=size/2; i++){
            if(s[i] == s[size-1-i])  continue;
            else{
                string temp = s;
                s.erase(s.begin()+i);
                temp.erase(temp.end()-1-i);
                return check(s,i)||check(temp,i);
            }
        }
        return true;
    }
};

class Solution {                            //false edition
public:
    bool validPalindrome(string s) {
        queue<char> right_side;
        queue<char> left_side;
        int size = s.size();
        for(int i=0; i<size/2; i++){
            left_side.push(s[i]);
            right_side.push(s[s.size()-1-i]);
        }

        if(size%2 == 1){
            left_side.push(s[size/2]);
            right_side.push(s[size/2]);
        }
        
        bool f = true;

        while(!left_side.empty() && !right_side.empty()){
            cout <<left_side.front()<<" "<<right_side.front()<<endl;
            if(left_side.front() == right_side.front()){
                left_side.pop();
                right_side.pop();
                continue;
            }
            else if(size%2 == 1 && f){
                cout <<"&*(&*(&(*&)))";
                char left_temp = left_side.front();
                char right_temp = right_side.front();
                left_side.pop();
                right_side.pop();
                f = false;
                cout <<left_temp<<right_temp<<left_side.front()<<right_side.front()<<endl;
                
                if(left_temp == right_side.front() && right_temp == left_side.front()){
                    int temp1 = left_side.front();
                    int temp2 = right_side.front();
                    left_side.pop();
                    right_side.pop();

                    if(temp1 == right_side.front()){
                        right_side.pop();
                        continue;
                    }
                    else if(temp2 == left_side.front()){
                        left_side.pop();
                        continue;
                    }
                }
                else if(left_temp == right_side.front()){
                    right_side.pop();
                    cout <<right_side.front();
                    cout <<"1";
                    continue;
                }
                else if(right_temp == left_side.front()){
                    left_side.pop();
                    cout <<"2";
                    continue;
                }
                else  return false;
            }
            else if(size%2 == 0 && f){
                char left_temp = left_side.front();
                char right_temp = right_side.front();
                left_side.pop();
                right_side.pop();
                f = false;

                if(left_side.empty() || right_side.empty())  return true;
                if(left_temp == right_side.front()){
                    right_side.pop();
                    continue;
                }
                else if(right_temp == left_side.front()){
                    left_side.pop();
                    continue;
                }
                else  return false;

            }
            else  return false;
        }
        return true;
    }
};


