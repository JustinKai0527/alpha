#include <iostream>
#include <vector>
#include <stack>
#include <cstdlib>
#include <algorithm>

using namespace std;

class Solution {
public:
    int largestInteger(int num) {
        string str = to_string(num);
        vector<char> odd;
        vector<char> even;
    
        for(auto i: str){
            if((i-48)%2 == 0){
                even.push_back(i);
            }
            else{
                odd.push_back(i);
            }
        }
        sort(even.begin(),even.end());
        sort(odd.begin(),odd.end());
        string ans;
        int a = 0, b = 0;
        for(auto i: str){
            if((i-48)%2 == 0){
                ans.push_back(even[a]);
                a++;
            }
            else{
                ans.push_back(odd[b]);
                b++;
            }
        }
        num = stoi(ans);
        return num;
    }
};