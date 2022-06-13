#include <iostream>
#include <vector>
using namespace std;
vector<int> root[];
class UnionFind {
public:
    // Constructor of Union-find. The size is the length of the root array.
    UnionFind(int sz) : root(sz);
    int find(int x);
    void unionSet(int x, int y);
    bool connected(int x, int y);
};

int find(int x) {
    while (x != root[x]) {
        x = root[x];
    }
    return x;
}

int find(int x) {                                           //The find function – optimized with path compression:
    if (x == root[x]) {
        return x;
    }
    return root[x] = find(root[x]);
}

void unionSet(int x, int y) {
    int rootX = find(x);
    int rootY = find(y);
    if (rootX != rootY) {
        root[rootY] = rootX;
    }
}

void unionSet(int x, int y) {                               //The union function – Optimized by union by rank:
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
    }
}

bool connected(int x, int y) {
    return find(x) == find(y);
}