#include <iostream>
#include <unordered_set>
#include <vector>

using namespace std;

class Solution {
public:
    int minSteps(string s, string t) {
        unordered_set<char> hashmap_s;
        unordered_set<char> hashmap_t;
        int count_s= 0;
        int count_t = 0;
        do{
            for(int i=0; i<s.size(); i++){
                if(hashmap_s.count(s[i]) <= 0){
                    hashmap_s.insert(s[i]);
                }
            }

            for(int i=0; i<t.size(); i++){
                if(hashmap_t.count(t[i]) <= 0){
                    hashmap_t.insert(t[i]);
                }
            }

            for(int i=0; i<t.size(); i++){
                if(hashmap_s.count(t[i]) <= 0){
                    count_s++;
                }
                else  s+=t[i];
            }

            for(int i=0; i<s.size(); i++){
                if(hashmap_t.count(s[i]) <= 0){
                    count_t++;
                }
                else  t+=s[i];
            }
        }while(s.size() != t.size());
    
        return count_s+count_t;
    }
};

int main(){
    string a = "nxkhahxvqy";
    string b = "nbhqyoxwnx";
    int c = 0;
    int d = 0;
    bool t = true;
    for(int i=0; i<a.size(); i++){
        t = true;
        for(int j=0; j<b.size(); j++){
            if(a[i] == b[j]){
                t = false;
                break;
            }
        }
        if(t)  c++;
    }

    for(int i=0; i<b.size(); i++){
        t = true;
        for(int j=0; j<a.size(); j++){
            if(b[i] == a[j]){
                t = false;
                break;
            }
        }
        if(t)  d++;
    }
    cout <<c+d;
    if(a.size()+c != b.size()+d)  cout<<"%^&";
    return c+d;
}