#include <iostream>
#include <vector>
#include <queue>
#include <stack>

using namespace std;

void check(vector<int>& stack, int top){
    int size = stack.size();
    
    if(size+1 < top)  stack.push_back(top);
    else{
        int count = 0;
        int i;
        bool f = false;
        for(i=size-1; i>=0; i--){
            if(stack[i] == top)  count++;
            else  break;
            if(count == top-1){
                f = true;
                break;
            }
        }
        if(f){
            stack.erase(stack.begin()+i,stack.end());
            // cout <<i;
        }
        else  stack.push_back(top);
    }
}
int main(){
    int num;
    cin>>num;
    vector<int> stack;

    for(int i=0; i<num; i++){

        int top;
        cin>>top;
        check(stack,top);
        // for(int i=0; i<stack.size(); i++){
        //     cout <<stack[i]<<" ";
        // }
        cout<<stack.size()<<endl;
    }
    return 0;
}



class Disjointed{

private:
    vector<int> root;
    vector<int> rank;
    int size;
};