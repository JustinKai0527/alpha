#include <iostream>
using namespace std;
int main(){
    string str = "";
    int a = 123;
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
    cout <<str;
    return 0;
}