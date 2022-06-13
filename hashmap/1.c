#include <stdio.h>

struct A{
    int a;
    int b;
};

int main(){
    A a;
    a.a = 4;
    a.b = 5;
    printf("%d\n%d",a.a,a.b);
    return 0;
}