#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){

    int times;
    cin>>times;
    while(times != 0){
        int r,g,b;
        cin>>r>>g>>b;
        int temp;
        if(g>r){
            temp = r;
            r = g;
            g = temp;
        }
        if(b>r){
            temp = r;
            r = b;
            b = temp;
        }
        if(b>g){
            temp = g;
            g = b;
            b = temp;
        }
        
        if(r==g && g==b){
            cout<<(r+g+b)/2;
        }
        else if(r==g && g>b){
            int valve = b/2;
            cout <<r+valve;
        }
        else if(r > g && g==b){
            int valve = r/2;
            if(valve >= g){
                cout <<2*g;
            }
            else{
                cout <<2*valve+(g-valve);
            }
        }
        else if(r > g && g > b){
            int detect = r-b;
            if(detect < g){
                cout <<r;
            }
            else{
                cout <<r-(detect-g);
            }
        }
        cout <<endl;
        times--;
    }

}