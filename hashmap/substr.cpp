#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    string minimizeResult(string s) {
        int ans = numeric_limits<int>::max(); // ans = int 的最大整數
        int x = s.find('+'); // s.find() 回傳+的index
        int n = s.length(); 
        int I = 0, J = 0;
        for (int i = 0; i < x; i++) {
            for (int j = x + 2; j <= n; j++) {

                int v = (i == 0 ? 1 : stoi(s.substr(0, i))) *
                            (stoi(s.substr(i, x - i)) + stoi(s.substr(x + 1, j - x - 1))) *
                                (j == n ? 1 : stoi(s.substr(j, n - j)));
                if (v < ans) {
                    ans = v;
                    I = i;
                    J = j;
                }
            }
        }
        s.insert(s.begin() + J, ')');
        s.insert(s.begin() + I, '(');
        return s;
    }
};