#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    long long minimumRemoval(vector<int>& beans) {
        long long ans;
        long long sum = 0;
        vector<int> b;
        sort(beans.begin(),beans.end());
        bool t = false;
        for(int i=0; i<beans.size(); i++){
            sum+=beans[i];
            if(i == beans.size()-1){
                if(!t){
                    b.push_back(beans[i]);
                }
                break;
            };
            if(beans[i] == beans[i+1]){
                b.back()+=beans[i];
                t = true;
            }
            else{
                t = false;
                b.push_back(beans[i]);
            }
        }
        long long temp;
        ans = sum-b[0];
        for(int i=1; i<b.size(); i++){
            temp = sum-b[i];
            if(temp > ans)  ans = temp;
        }
        
        return sum-ans;
    }
};