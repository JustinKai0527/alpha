#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int mySqrt(int x) {
        if(x == 1)  return 1;
        int left = 1;
        int right = x-1;
        while(left <= right){
            int ans = (left+right)/2;
            if(x/ans == ans)  return ans;
            else if(x/ans > ans)  left = ans+1;
            else if(x/ans < ans)  right = ans-1;
            // cout <<left<<right<<endl;
        }
        return (right+left)/2;
    }
};


class Solution {
public:
    int mySqrt(int x) {                                                 //100% fast
    int s = 0;
    int e = x;
    long long int mid = s + (e - s)/2;
    long long int ans;
    while(s<=e) {
        long long int square = mid * mid;
        if(square == x){
            return mid;
        } else if(square < x) {
            ans = mid;
            s = mid + 1;
        } else {
            e = mid - 1;
        }
        mid = s + (e - s)/2;
    }
    return ans;
}
};

class Solution {                                                                  
public:
    int mySqrt(int x) {
        if(x == 1)  return 1;
        long long int left = 1;
        long long int right = x-1;
        while(left <= right){
            long long int ans = ((left+right)/2);
            if(x == ans*ans)  return ans;
            else if(x > ans*ans)  left = ans+1;
            else if(x < ans*ans)  right = ans-1;
        }
        return (right+left)/2;
    }
};