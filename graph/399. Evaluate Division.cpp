#include <iostream>
#include <vector>
#include "UnionFind.h"
#include <stack>

using namespace std;






class Solution {
public:
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        vector<double> ans;
        UnionFind Graph(queries.size());     
    }
};

// class Disjoint_Set{
// public:
//     Disjoint_Set(int size): rank(size),root(size),count(size){
//         for(int i=0; i<size; i++){
//             root[i] = i;
//             rank[i] = 1;
//         }
//     }
//     int find(int x){
//         if(root[x] == x)    return x;
//         return root[x] = find(root[x]);
//     }
//     void Union(int x, int y){
//         int rootx = find(x);
//         int rooty = find(y);
//         if(rootx != rooty){
//             if(rank[rootx] > rank[rooty]){
//                 root[rooty] = root[rootx];     // root[rootY] = rootX    is same
//             }
//             else if(rank[rootx] < rank[rooty]){
//                 root[rootx] = root[rooty];
//             }
//             else{
//                 rank[rootx]+=1;
//                 root[rooty] = root[rootx];
//             }
//             count--;
//         }
//     }
//     bool isConnected(int x, int y){
//         return find(x) == find(y);
//     }
//     int sum_Union(){
//         return count;
//     }
// private:
//     vector<int> rank;
//     vector<int> root;
//     int count;
// };


int main(void){
    stack<int> s;
    for(int i=0; i<5; i++){
        s.push(i);
    }
    
}