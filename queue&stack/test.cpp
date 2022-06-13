#include <iostream>
using namespace std;
int main()
{
    string s = "abcde";
    s.erase(s.end() - 2);
    cout << s[3];
    return 0;
