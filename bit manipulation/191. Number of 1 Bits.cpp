#include <iostream>
#include <vector>

using namespace std;

typedef signed char int8_t;
typedef short int int16_t;
typedef int int32_t;
typedef long int int64_t;

typedef unsigned char uint8_t;
typedef unsigned short int uint16_t;
typedef unsigned int uint32_t;
typedef unsigned long int uint64_t;
                                    //內建的uint就是這樣來的
class Solution {
public:
    int hammingWeight(uint32_t n) {
        int count = 0;
        while(n){
            if(n%2)  count++;
            n/=2;
        }
        return count;
    }
};

#include <sys/types.h>

int main(){
 
    unsigned long long value=0xFFFFFFFFFFFFFFFF;
    uint8_t number8 = value;
    uint16_t number16 = value;
    uint32_t number32 = value;
    uint64_t number64 = value;
    
            //為啥要轉型  因為uint8_t 其實是typedef unsigned_char 
    cout <<number8<<endl;
    cout << (int)number8 << endl;   //得到255
    cout << number16 << endl;   //得到65535
    cout << number32 << endl;   //得到4294967295
    cout << number64 << endl;   //得到18446744073709551615
}