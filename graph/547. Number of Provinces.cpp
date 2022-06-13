#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Graph{
public:
    Graph(int size) {
        root.resize(size);
        rank.resize(size);
        for(int i=0; i<size; i++){
            rank[i] = 1;
            root[i] = i;
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
                root[rooty] = rootx;
            }
            else if(rank[rootx] < rank[rooty]){
                root[rootx] = rooty;
            }
            else{
                rank[rootx] += 1;
                root[rooty] = rootx;
            }
        }
    }
    bool connected(int x, int y){
        return find(x) == find(y);
    }


private:
    vector<int> root;
    vector<int> rank;
};
class Solution {
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        Graph Province(isConnected.size());
        for(int i=0; i<isConnected.size(); i++){
            for(int j=0; j<isConnected.size(); j++){
                if(i != j && isConnected[i][j] == 1){
                    if(!Province.connected(i,j)){
                        Province.Union(i,j);
                    }
                }
            }
        }
        bool check[isConnected.size()];
        for(int i=0; i<isConnected.size(); i++){
            Province.find(i);
            check[i] = false;
        }
        int total = 0;
        for(int i=0; i<isConnected.size(); i++){
            if(!check[Province.find(i)]){
                total++;
                check[Province.find(i)] = true;
            }
        }
        return total;
    }
};


                                                            
class UnionFind {                                                       //leetcode tutorial example
public:
    UnionFind(int sz) : root(sz), rank(sz), count(sz) {
        for (int i = 0; i < sz; i++) {
            root[i] = i;
            rank[i] = 1;
        }
    }

    int find(int x) {
        if (x == root[x]) {
            return x;
        }
        return root[x] = find(root[x]);
    }

    void unionSet(int x, int y) {
        int rootX = find(x);
        int rootY = find(y);
        if (rootX != rootY) {
            if (rank[rootX] > rank[rootY]) {
                root[rootY] = rootX;
            } else if (rank[rootX] < rank[rootY]) {
                root[rootX] = rootY;
            } else {
                root[rootY] = rootX;
                rank[rootX] += 1;
            }
            count--;
        }
    }

    int getCount() {
        return count;
    }

private:
    vector<int> root;
    vector<int> rank;
    int count;
};

class Solution {
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        if (isConnected.size() == 0) {
            return 0;
        }
        int n = isConnected.size();
        UnionFind uf(n);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (isConnected[i][j] == 1) {
                    uf.unionSet(i, j);
                }
            }
        }
        return uf.getCount();
    }
};
