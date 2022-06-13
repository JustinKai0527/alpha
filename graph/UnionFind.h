#ifndef _UNIONFIND_H
#define _UNIONFIND_H

#include <iostream>
#include <vector>

using namespace std;

class UnionFind{
public:
    UnionFind(int size): root(size), rank(size), count(size){
        for(int i=0; i<size; i++){
            root[i] = i;
            rank[i] = 1;
        }
    }

    int find(int x){
        if(x == root[x])  return x;
        else  return root[x] = find(root[x]);
    }

    void Union(int x, int y){
        int rootx = find(x);
        int rooty = find(y);

        if(rootx != rooty){
            if(rank[rootx] > rank[rooty]){
                root[rooty] = rootx;
            }
            else if(rank[rootx] = rank[rooty]){
                root[rootx] = rooty;
            }
            else{
                rank[rootx]++;
                root[rooty] = rootx;
            }
            count--;
        }
    }

    int get_count(void){
        return count;
    }
private:
    vector<int> root;
    vector<int> rank;
    int count = 0;
};

#endif