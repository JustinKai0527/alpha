#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <cmath>
using namespace std;


class Solution {
public:
    int compare(stack<char>& v1, stack<char>& v2){
        int sum1 = 0, sum2 = 0, count = 0;
        while(!v1.empty()){
            if(v1.top() != '0')  sum1 += (v1.top() - 48) * pow(10, count);
            count++;
            v1.pop();
        }
        count = 0;
        while(!v2.empty()){
            if(v2.top() != '0')  sum2 += (v2.top() - 48) * pow(10, count);
            count++;
            v2.pop();
        }

        if(sum1 > sum2)  return 1;
        else if(sum1 < sum2)  return -1;
        return  0;
    }
    int compareVersion(string version1, string version2) {
        queue<stack<char>> ver1;
        queue<stack<char>> ver2;
        stack<char> v1;
        stack<char> v2;
        stack<char> clear;
        int count = 0;
        for(int i=0; i<version1.size(); i++){
            if(version1[i] != '.')  v1.push(version1[i]);
            
            if(version1[i] == '.' || i == version1.size()-1){
                ver1.push(v1);
                v1 = clear;
            }
        }
        for(int i=0; i<version2.size(); i++){
            if(version2[i] != '.')  v2.push(version2[i]);
            
            if(version2[i] == '.' || i == version2.size()-1){
                ver2.push(v2);
                v2 = clear;
            }
        }
        

        while(!ver1.empty()){
            while(!ver1.front().empty()){
                cout <<ver1.front().top();
                ver1.front().pop();
            }
            cout <<endl;
            ver1.pop();
        }
        while(!ver2.empty()){
            while(!ver2.front().empty()){
                cout <<ver2.front().top();
                ver2.front().pop();
            }
            cout<<endl;
            ver2.pop();
        }

        if(ver1.size() > ver2.size()){
            while(!ver1.empty()){
                int check = compare(ver1.front(), ver2.front());
                if(check != 0)  return check;
                ver1.pop();
                if(!ver2.empty())  ver2.pop();
            }
        }
        else{
            while(!ver2.empty()){
                int check = compare(ver1.front(), ver2.front());
                if(check != 0)  return check;
                if(!ver1.empty())  ver1.pop();
                ver2.pop();
            }
        }
        
        return 0;
    }
};



class Solution {
public:
    int compare(stack<char>& v1, stack<char>& v2){
        while(!v1.empty() || !v2.empty()){
            // cout <<v1.top()<<v2.top();

            if(v1.top() == v2.top()){
                v1.pop();
                v2.pop();
                // cout << "2";
                continue;
            }
            
            if(v1.top()-48 > v2.top()-48)  return 1;
            else if(v1.top()-48 < v2.top()-48)  return -1;
        
        }
        if(v1.empty()){
            for(int i=0; i<v2.size(); i++){
                if(v2.top() != '0')  return -1;
                else  v2.pop();
            }
        }
        else if(v2.empty()){
            for(int i=0; i<v1.size(); i++){
                if(v1.top() != '0')  return 1;
                else  v1.pop();
            }
        }

        return  0;
    }
    int compareVersion(string version1, string version2) {
        queue<queue<char>> ver1;
        queue<queue<char>> ver2;
        stack<char> v1;
        stack<char> v2;
        int count = 0;
        for(int i=0; i<version1.size(); i++){
            if(version1[i] != '.' && i != version1.size()-1){
                v1.push(version1[i]);
                continue;
            }
            if(version1[i] != '.')  v1.push(version1[i]);
            for(int j=count; j<version2.size(); j++){
                if(version2[j] == '.')  break;
                v2.push(version2[j]);
                // cout << v2.top();
                count = j+1;
            }
            int check = compare(v1,v2);
            // cout <<  check<<endl;
            if(check != 0)  return  check;
        }
        if(count != version2.size()-1){
            for(int i=count; i<version2.size(); i++){
                if(version2[i] != '0')  return  -1;
            }
        }
        else{
            for(int i=count; i<version1.size(); i++){
                if(version1[i] != '0')  return  1;
            }
        }
        return 0;
    }
};