#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    int factorial(int j){
        if(j == 1)  return 1;
        return j*factorial(j-1);
    }
    int threeSumMulti(vector<int>& arr, int target) {
        unordered_map<int,int> hashmap;
        int size = arr.size();
        vector<int> v;

        for(int i=0; i<size; i++){
            if(arr[i] > target )  continue;
            hashmap[arr[i]]++;
        }
        int count = 0;
        int Target;
        for(int i=0; i<size; i++){
            Target = target-arr[i];
            int j=0,k=size-1;
            bool f = false;
            while(j<=k){
                if(arr[j]+arr[k] == Target && j != k && i != j && k != i){
                    f = true;
                    break;
                }
                else if(arr[j]+arr[k] < Target){
                    j++;
                }
                else if(arr[j]+arr[k] > Target){
                    k--;
                }
            }
            cout <<i<<j<<k<<endl;
        }

    }
};