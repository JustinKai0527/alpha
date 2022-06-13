#include <iostream>
#include <vector>
#include <stack>
#include <queue>
using namespace std;

class Solution {                                                //queue version
public:
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        if(source == destination)    return true;
        queue<int> q;
        vector<vector<int>> adjacency_list(n);
        for(int i=0; i<edges.size(); i++){
            adjacency_list[edges[i][0]].push_back(edges[i][1]);
            adjacency_list[edges[i][1]].push_back(edges[i][0]);
        }
        q.push(source);
        vector<bool> check;
        for(int i=0; i<n; i++){
            check.push_back(true);
        }
        int temp;
        while(!q.empty()){
            if(check[q.front()]){
                check[q.front()] = false;
                temp = q.front();
                q.pop();
                for(int i=0; i<adjacency_list[temp].size(); i++){
                    if(adjacency_list[temp][i] == destination)    return true;
                    else if(check[adjacency_list[temp][i]]){
                        q.push(adjacency_list[temp][i]);
                    }
                }
            }
            else q.pop();
        }
        return false;
    }
};



class Solution {                                    //leetcode example  queue version
public:
    bool validPath(int n, vector<vector<int>>& edges, int start, int end) {
        vector<vector<int>> adjacency_list(n);
        for (vector<int> edge : edges) {
            adjacency_list[edge[0]].push_back(edge[1]);
            adjacency_list[edge[1]].push_back(edge[0]);
        }
        
        queue<int> q;
        q.push(start);
        vector<bool> seen(n);
        seen[start] = true;
        
        while (!q.empty()) {
            // Get the current node.
            int node = q.front();
            q.pop();
            
            // Check if we have reached the target node.
            if (node == end) {
                return true;
            }
            
            // Add all neighbors to the stack.
            for (int neighbor : adjacency_list[node]) {
                // Check if neighbor has been added to the queue before.
                if (!seen[neighbor]) {
                    seen[neighbor] = true;
                    q.push(neighbor);
                }
            }
        }
        
        return false;
    }
};

bool check(vector<int>& v, int a){                              //stack version
    for(int i=0; i<v.size(); i++){
        if(v[i] == a)    return false;
    }
    return true;
}
class Solution {
public:
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        if(source == destination)    return true;
        stack<int> s;
        vector<vector<int>> adjacency_list(n);     
        for(int i=0; i<edges.size(); i++){                          //construct adjacency_list 
            adjacency_list[edges[i][0]].push_back(edges[i][1]);
            adjacency_list[edges[i][1]].push_back(edges[i][0]);
        }   
        s.push(source);
        vector<int> seen;
        while(!s.empty()){
            if(check(seen,s.top())){
                seen.push_back(s.top());
                s.pop();
                for(int i=0; i<adjacency_list[seen.back()].size(); i++){
                    if(adjacency_list[seen.back()][i] == destination)    return true;
                    else if(check(seen,adjacency_list[seen.back()][i])){
                        s.push(adjacency_list[seen.back()][i]);
                    }
                
                }
            }
            else    s.pop();
        }
        return false;
    }
};





class Solution {                             //leetcode example  stack version
public:
    bool validPath(int n, vector<vector<int>>& edges, int start, int end) {
        vector<vector<int>> adjacency_list(n);
        for (vector<int> edge : edges) {
            adjacency_list[edge[0]].push_back(edge[1]);
            adjacency_list[edge[1]].push_back(edge[0]);
        }
        
        stack<int> st;
        st.push(start);
        vector<bool> seen(n);
        
        while (!st.empty()) {
            // Get the current node.
            int node = st.top();
            st.pop();
            
            // Check if we have reached the target node.
            if (node == end) {
                return true;
            }
            
            // Check if we've already visited this node.
            if (seen[node]) {
                continue;
            }
            seen[node] = true;
            
            // Add all neighbors to the stack.
            for (int neighbor : adjacency_list[node]) {
                st.push(neighbor);
            }
        }
        
        return false;
    }
};


// class Disjoint_Set{                                              //Disjoint_Set solution
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

// class Solution {
// public:
//     bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
//         Disjoint_Set Graph(n);
//         for(int i=0; i<edges.size(); i++){
//             Graph.Union(edges[i][0],edges[i][1]);
//         }
//         return Graph.isConnected(source,destination);
//     }
// };