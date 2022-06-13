#include <stdio.h>
#include <iostream>

using namespace std;

int main(void){
    long long int count = 0;
    int times;
    scanf("%d",&times);
    long long int competitions;

    while(times){
        scanf("%d",&competitions);
        int left,right,mid;
        left = 0;
        right = competitions*2;
        bool f = false;

        while(left<=right){
            count = 0;
            mid = left+(right-left)/2;  
            int temp = mid;
            cout <<left<<" "<<mid<<" "<<right<<" ";
            while(true){
                if(mid%2 == 0){
                    mid/=2;
                    count+=mid;
                }
                else if(mid == 1)  break;
                else{
                    count+=((mid-1)*mid)/2;
                    break;
                }
            }
            cout <<count<<endl;
            if(count == competitions){   
                printf("%d\n",temp);
                f = true;
                break;
            }
            else if(count>competitions)  right = temp-1;
            else  left = temp+1;
        }
        if(!f)  printf("-1\n");
        times--;
    }
    return 0;
}
