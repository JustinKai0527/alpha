#include <iostream>
#include <vector>
using namespace std;
int main(){

    vector<vector<int>> ans(10);
    
    for(int i=0; i<10; i++){
        for(int j=0; j<10; j++){
            // cout <<"2";
            ans[i][j] = 1;
            // cout <<"2";
        }
    }
    
    for(int i=0; i<10; i++){
        for(int j=0; j<10; j++){
            cout <<ans[i][j]<<" ";
        }
        cout <<endl;
    }

    return 0;
}

// #include <iostream>
// #include <vector>
// #include <queue>
// using namespace std;

// int main(){
//     vector<int> ans(10);             // 宣告1個vector，裡面有10個int空間。
//     for(int i=0; i<10; i++){
//         ans[i] = i;
//     }

//     vector<int> ans[10];             // 宣告10個vector，每一個都可以存int。
//     return 0;
// }


