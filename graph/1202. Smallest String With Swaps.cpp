#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

class Disjoint_Set{
public:
    Disjoint_Set(int size): rank(size),root(size),count(size){
        for(int i=0; i<size; i++){
            root[i] = i;
            rank[i] = 1;
        }
    }
    int find(int x){
        if(root[x] == x)    return x;
        return root[x] = find(root[x]);
    }
    void Union(int x, int y){
        int rootx = find(x);
        int rooty = find(y);
        if(rootx != rooty){
            if(rank[rootx] > rank[rooty]){
                root[rooty] = root[rootx];     // root[rootY] = rootX    is same
            }
            else if(rank[rootx] < rank[rooty]){
                root[rootx] = root[rooty];
            }
            else{
                rank[rootx]+=1;
                root[rooty] = root[rootx];
            }
            count--;
        }
    }
    bool isConnected(int x, int y){
        return find(x) == find(y);
    }
    int sum_Union(){
        return count;
    }
private:
    vector<int> rank;
    vector<int> root;
    int count;
};

bool change(const char a, const char b){
    return a>b;
}

class Solution {
public:
    string smallestStringWithSwaps(string s, vector<vector<int>>& pairs) {
        Disjoint_Set str(s.size());
        for(int i=0; i<pairs.size(); i++){
            str.Union(pairs[i][0],pairs[i][1]);
        }
        

        unordered_map<int,vector<char>> hashmap;
        for(int i=0; i<s.size(); i++){
            hashmap[str.find(i)].push_back(s[i]);
        }
        for(auto it = hashmap.begin(); it != hashmap.end(); it++){
            sort(it->second.begin(),it->second.end(),change);
        }
        for(int i=0; i<s.size(); i++){
            s[i] = hashmap[str.find(i)].back();
            hashmap[str.find(i)].pop_back();
        }
        return s;
    }
};



// class Solution {                                     // wrong answer
// public:
//     string smallestStringWithSwaps(string s, vector<vector<int>>& pairs) {
//         Disjoint_Set STRING(s.size());
//         for(int i=0; i<pairs.size(); i++){
//             STRING.Union(pairs[i][0],pairs[i][1]);
//         }  
        
//         bool check[s.size()];
//         for(int i=0; i<s.size(); i++){
//             STRING.find(i);
//             check[i] = true;
//         }
        
//         vector<vector<string>> reset;
//         for(int i=0; i<s.size(); i++){
            
//         }
//     }
// };
