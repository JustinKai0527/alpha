#include <iostream>
#include <vector>

using namespace std;

int main(void){
    int y;
    float temp;

    while(scanf("%f",&temp)!=EOF){
        y=*((int*)&temp);                       //float translate to int but the value change differerntly
        printf("y%i",y);
        cout <<endl;
    }
    return 0;
}