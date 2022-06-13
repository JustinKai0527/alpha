#include <iostream>
#include <vector>

using namespace std;

int num;

void permutation(string ans, vector<bool>& f, vector<char>& arr, int level){
    if(level == num){
        cout <<ans<<endl;
        return;
    }

    for(int i=0; i<num; i++){
        if(f[i]){
            f[i] = false;
            ans.push_back(arr[i]);
            permutation(ans,f,arr,level+1);
            ans.pop_back();
            f[i] = true;
        }
    }
}

int main(void){
    int level = 0;
    cin>>num;
    string ans;
    vector<bool> f(num,true);
    vector<char> arr;

    for(int i=1; i<=num; i++){
        arr.push_back((char)(48+i));
        f[i-1] = true;
    }

    permutation(ans,f,arr,level);

    return 0;
}