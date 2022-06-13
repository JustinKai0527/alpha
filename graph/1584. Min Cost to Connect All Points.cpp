#include <iostream>
#include <vector>
#include <cmath>
#include <queue>
#include <algorithm>

using namespace std;

class Disjointed_Sets{
public:
    Disjointed_Sets(int size): root(size), rank(size), count(size){
        for(int i=0; i<size; i++){
            root[i] = i;
            rank[i] = 1;
        }
    };

    int find(int x){
        if(x == root[x]) return x;
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
            count--;
        }
    }

    bool isConnected(int x, int y){
        return find(x) == find(y);    // 不能寫root[x] == root[y]; 因為或許還不是   //The find function – optimized with path compression:
    }

    int sum_of_Union(void){
        return count;
    }
private:
    vector<int> root;
    vector<int> rank;
    int count;
};

class Edge{
public:

    Edge(int _start, int _end, int dis): start(_start), end(_end), distance(dis){};
    int start;
    int end;
    int distance;

};

bool operator<(const Edge& edge1, const Edge& edge2) {    //use for sort to class 
    return edge1.distance < edge2.distance;
}

// bool compare(const Edge& edge1, const Edge& edge2){
//     return edge1.distance < edge2.distance;
// }
// class Edge{
// public:

//     Edge(int _start, int _end, vector<vector<int>>& points): start(_start), end(_end){
//         distance = abs(points[_start][1]-points[end][1]) + abs(points[_start][0]-points[end][0]);
//     }
//     int start;
//     int end;
//     int distance;

// };


// void insert(vector<Edge>& edge, Edge& e){
//     if(edge.empty() || edge.back().distance <= e.distance){
//         edge.push_back(e);
//         return;
//     }
//     vector<Edge> temp;
//     for(int i=0; i<edge.size(); i++){
//         if(e.distance < edge[i].distance){
//             // edge.insert(edge.begin()+0,e);                      //why can't edge.insert(i,e);   bc: insert i 你不知道是從哪開始
//             temp.push_back(e);
//             for(int j=i; j<edge.size(); j++){
//                 temp.push_back(edge[j]);
//             }
//             break;
//         }
//         else{
//             temp.push_back(edge[i]);
//         }
//     }
//     edge = temp;
// }

// void insert(vector<Edge>& edge, Edge& e){
//     if(edge.empty()){
//         edge.push_back(e);
//         return;
//     }
//     else if(edge[edge.size()-1].distance < e.distance){
//         edge.push_back(e);
//         return;
//     }
//     else{
//         for(int i=0; i<edge.size(); i++){
//             if(edge[i].distance >= e.distance){
//                 edge.insert(edge.begin() + i, e);
//                 return ;
//             }
//         }
//     }
// }
class Solution {
public:

    int minCostConnectPoints(vector<vector<int>>& points) {
        Disjointed_Sets Graph(points.size());
        vector<Edge> edge;
        int delta_x, delta_y;
        for(int i=0; i<points.size(); i++){
            for(int j=i+1; j<points.size(); j++){
                delta_x = abs( points[i][0] - points[j][0]);
                delta_y = abs( points[i][1] - points[j][1]);
                Edge e(i,j,delta_x+delta_y);
                // cout <<i<<" "<<j<<endl;
                // if(edge.empty()){
                //     edge.push_back(e);
                //     // return;
                // }
                // else if(edge[edge.size()-1].distance < e.distance){
                //     edge.push_back(e);
                //     // return;
                // }
                // else{
                //     for(int i=0; i<edge.size(); i++){
                //         if(edge[i].distance >= e.distance){
                //             edge.insert(edge.begin() + i, e);
                //             // return ;
                //             break;
                //         }
                //     }
                // }
                edge.push_back(e);
            }
        }
        sort(edge.begin(),edge.end());
        // return edge.front().distance;
        int sum = 0;
        // for(int i=0; i<edge.size(); i++){
            // cout <<edge[i].start<<" "<<edge[i].end<<" "<<edge[i].distance<<endl;
        // }
        for(int i=0; i<edge.size(); i++){
            if(!Graph.isConnected(edge[i].start, edge[i].end)){
                Graph.Union(edge[i].start, edge[i].end);
                // cout <<edge[i].start <<" + "<<edge[i].end<<" + ";
                sum += edge[i].distance;
                // cout <<sum<<" & ";
                // cout <<i;
                if(Graph.sum_of_Union() == 1)    break;
            }

        }
        
        return sum;
    }
};


// class Edge {
// public:
//     int point1;
//     int point2;
//     int cost;
//     Edge(int point1, int point2, int cost)
//         : point1(point1), point2(point2), cost(cost) {}
// };

// // Overload the < operator.
// bool operator<(const Edge& edge1, const Edge& edge2) {
//     return edge1.cost > edge2.cost;
// }

// class UnionFind {
// public:
//     UnionFind(int sz) : root(sz), rank(sz) {
//         for (int i = 0; i < sz; i++) {
//             root[i] = i;
//             rank[i] = 1;
//         }
//     }

//     int find(int x) {
//         if (x == root[x]) {
//             return x;
//         }
//         return root[x] = find(root[x]);
//     }

//     void unionSet(int x, int y) {
//         int rootX = find(x);
//         int rootY = find(y);
//         if (rootX != rootY) {
//             if (rank[rootX] > rank[rootY]) {
//                 root[rootY] = rootX;
//             } else if (rank[rootX] < rank[rootY]) {
//                 root[rootX] = rootY;
//             } else {
//                 root[rootY] = rootX;
//                 rank[rootX] += 1;
//             }
//         }
//     }

//     bool connected(int x, int y) {
//         return find(x) == find(y);
//     }

// private:
//     vector<int> root;
//     vector<int> rank;
// };

// class Solution {
// public:
//     // Kruskal's algorithm
//     int minCostConnectPoints(vector<vector<int>>& points) {
//         if (points.size() == 0) {
//             return 0;
//         }
//         int sz = points.size();
//         priority_queue<Edge> pq;
//         UnionFind uf(sz);

//         for (int i = 0; i < sz; i++) {
//             vector<int>& coordinate1 = points[i];
//             for (int j = i + 1; j < sz; j++) {
//                 vector<int>& coordinate2 = points[j];
//                 // Calculate the distance between two coordinates.
//                 int cost = abs(coordinate1[0] - coordinate2[0]) +
//                            abs(coordinate1[1] - coordinate2[1]);
//                 Edge edge(i, j, cost);
//                 pq.push(edge);
//             }
//         }

//         int result = 0;
//         int count = sz - 1;
//         while (!pq.empty() && count > 0) {
//             Edge edge = pq.top();
//             pq.pop();
//             if (!uf.connected(edge.point1, edge.point2)) {
//                 uf.unionSet(edge.point1, edge.point2);
//                 result += edge.cost;
//                 count--;
//             }
//         }
//         return result;
//     }
// };

// int main() {
//     vector<vector<int>> points = {{0, 0}, {2, 2}, {3, 10}, {5, 2}, {7, 0}};
//     Solution solution;
//     cout << "Minimum Cost to Connect Points = " << solution.minCostConnectPoints(points) << endl;
//     return 0;
// }


class Solution {        // another example 
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        int n = points.size();
        vector<pair<int, int>> adj[n];
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                int dist = abs(points[i][0] - points[j][0]) + abs(points[i][1] - points[j][1]);
                adj[i].push_back({j, dist});
                adj[j].push_back({i, dist});
            }
        }
        
        vector<int> key(n, INT_MAX);
        vector<int> parent(n, -1);
        vector<bool> mst(n, false);
        
        key[0] = 0;
        
        for(int count = 0;count<n-1;count++){
            int mini = INT_MAX, u;
            
            // find the minimum 
            for(int i=0;i<n;i++){
                if(mini>key[i] and mst[i] == false){
                    u=i, mini = key[i];
                }
            }
            
            mst[u] = true;
            
            for(auto it:adj[u]){
                int node = it.first;
                int weight = it.second;
                if(mst[node] == false and key[node] > weight){
                    parent[node] = u, key[node] = weight;
                }
            }
        }
        int sum = 0;
        for(int i=0;i<n;i++){
            sum += key[i];
        }
        return sum;
    }
};



class DSU{              // another example
    public:
    vector<int> size;
    vector<int> parent;
    DSU(int n){
        for(int i=0;i<=n;i++){
            parent.push_back(i);
            size.push_back(1);
        }
    }
    void Union(int u ,int v){
        int pu = findParent(u);
        int pv = findParent(v);
        if(pv==pu){
            return;
        }
        if(size[pv] > size[pu]){
                parent[pu] = pv;
                size[pv]+=size[pu];
        }else{
            parent[pv]=pu;
            size[pu]+=size[pv];
        }
    }
    int findParent(int node){
        if(parent[node]==node){
            return node;
        }
        return parent[node] = findParent(parent[node]);
    }
};
class point{
    public:
    int u,v;
    int wt;
    point(int _u,int _v,int _wt){
        u=_u;
        v=_v;
        wt=_wt;
    }
};
class Solution {
    public:
    bool static cmp(point &p1,point &p2){
        return p1.wt < p2.wt;
    }
    int minCostConnectPoints(vector<vector<int>>& points) {
        int n = points.size();
        vector<point> edges;
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                int wt = abs(points[i][0]-points[j][0]) + abs(points[i][1]-points[j][1]);
                edges.push_back(point(i,j,wt));
            }
        }
        
        int cost=0;
        DSU d(n);
        sort(edges.begin(),edges.end(),cmp);
        // for(auto it : edges){
        //     cout<<it.u<<" "<<it.v<<" "<<it.wt<<" \n";
        // }
        int s=0;
        for(auto edge : edges){
            int u = edge.u;
            int v= edge.v;
            int wt= edge.wt;
            if(d.findParent(u) != d.findParent(v)){
                cost+=wt;
                d.Union(u,v);
                s++;
            }
            if(s==n-1){
                break;
            }
        }
        
        return cost;
    }
};