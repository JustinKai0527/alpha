#include <iostream>
#include <string>
#include<algorithm>
using namespace std;

// string str;
// string Ans; 
// bool choosed[100] = {0}; 

// void backtracking(const int &N);

// int main()
// {
//     char ch[5];
//     int asc[5];
//     for (int i = 0; i < 5; i++){
//         cin >> ch[i];
//     }
//     for (int i = 0; i < 5; i++){
//         str[i] = ch[i];
//     }
//     for (int i = 0; i < 5; i++){
//         asc[i] = str[i];
//     }
//     sort(asc,asc + 5);
//     for (int i = 0; i < 5; i++){
//         str[i] = asc[i];
//     }
    
    
//     backtracking(5);
// }
// void backtracking(const int &N)    
// {
//     if (Ans.size() == N) {         
//         cout << Ans << endl;
//         return;
//     }
//     for (int i = 0; i < N; ++i) {
//         if (choosed[i] == 0){      
//             Ans.push_back(str[i]); 
//             choosed[i] = 1;        

//             backtracking(N);       

//             Ans.pop_back();        
//             choosed[i] = 0;       
//         }
//     }
// }


