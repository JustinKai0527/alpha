#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

class dfu{
public:
    dfu(int size): rank(size), root(size), count(size), check(size){
        for(int i=0; i<size; i++){
            rank[i] = 1;
            root[i] = i;
            check[i] = false;
        }
    }

    int find(int x){
        if(x == root[x])  return x;
        return root[x] = find(root[x]);
    }

    void Union(int x, int y){
        int rootx = find(x);
        int rooty = find(y);
        if(rootx != rooty){
            if(rank[rootx] > rank[rooty]){
                root[rooty] = rootx;
            }
            else if(rank[rooty] < rank[rootx]){
                root[rootx] = rooty;
            }
            else{
                rank[rootx]+=1;
                root[rooty] = rootx;
            }
            count--;
        }
    }

    bool isConnected(int x, int y){
        return find(x) == find(y);
    }

    int sum_of_Union(){
        return count;
    }

    vector<bool> check;

private:
    vector<int> rank;
    vector<int> root;
    int count;

};

class Edge{
public:
    Edge(int s, int e, int dis): start(s), end(e), distance(dis){};
    int start;
    int end;
    int distance;
};

bool compare(const Edge &a, const Edge& b){
    return a.distance < b.distance;
}

class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        dfu Graph(points.size());
        vector<Edge> edge_available;
        vector<vector<Edge>> edge_unavailable(points.size());
        int delta_x, delta_y;
        bool detect[points.size()][points.size()];
        for(int i=0; i<points.size(); i++){
            
            for(int j=0; j<i+1; j++){
                Edge e(-1,-1,-1);
                edge_unavailable[i].push_back(e);
                detect[i][j] = true;
            }
            for(int j=i+1; j<points.size(); j++){
                detect[i][j] = true;
                delta_x = abs(points[i][0] - points[j][0]);
                delta_y = abs(points[i][1] - points[j][1]);
                Edge e(i,j,delta_x+delta_y);
                edge_unavailable[i].push_back(e);
            }
        }
        
        for(int i=0; i<points.size(); i++){
            for(int j=i+1; j<points.size(); j++){
                cout <<edge_unavailable[i][j].start<<" "<<edge_unavailable[i][j].end<<" "<<edge_unavailable[i][j].distance<<endl;
            }
        }
        

        int new_vertice = 0;
        Graph.check[0] = true;
        int sum = 0;

       
        while(true){
            for(int i=new_vertice+1; i<edge_unavailable[new_vertice].size(); i++){
                if(!detect[i][new_vertice])  break;
                detect[i][new_vertice] = false;
                edge_available.push_back(edge_unavailable[new_vertice][i]);
                // edge_unavailable[new_vertice].erase(edge_unavailable[new_vertice].begin()+i);
                // i--;                                        //bc   erase()   so edge_unavailable.size()--;
                
            }
            for(int i=0; i < new_vertice; i++){
                if(!detect[i][new_vertice])  break;
                detect[i][new_vertice] = false;
                edge_available.push_back(edge_unavailable[i][new_vertice]);
            }
            sort(edge_available.begin(),edge_available.end(),compare);
            for(int i=0; i<edge_available.size(); i++){
                cout <<edge_available[i].start<<" " << edge_available[i].end<<" " << edge_available[i].distance<<endl;
            }
            for(int i=0; i<edge_available.size(); i++){
                if(!Graph.isConnected(edge_available[i].start,edge_available[i].end)){
                    Graph.Union(edge_available[i].start,edge_available[i].end);
                    if(!Graph.check[edge_available[i].start]){
                        new_vertice = edge_available[i].start;
                        Graph.check[new_vertice] = true;
                    }
                    else{
                        new_vertice = edge_available[i].end;
                        Graph.check[new_vertice] = true;
                    }
                    sum += edge_available[i].distance;
                    cout <<"&*("<<edge_available[i].start<<" " <<edge_available[i].end<<" " <<edge_available[i].distance<<" ";
                    cout <<sum<<endl;
                    edge_available.erase(edge_available.begin()+i);
                    break;
                }
            }
            if(Graph.sum_of_Union() == 1)  break;
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

// class Solution {
// public:
//     // Prim's algorithm
//     int minCostConnectPoints(vector<vector<int>>& points) {
//         if (points.size() == 0) {
//             return 0;
//         }
//         int sz = points.size();
//         priority_queue<Edge> pq;
//         vector<bool> visited(sz);
//         int result = 0;
//         int count = sz - 1;
//         // Add all edges from points[0] vertex
//         vector<int>& coordinate1 = points[0];
//         for (int j = 1; j < sz; j++) {
//             // Calculate the distance between two coordinates
//             vector<int>& coordinate2 = points[j];
//             int cost = abs(coordinate1[0] - coordinate2[0]) +
//                        abs(coordinate1[1] - coordinate2[1]);
//             Edge edge(0, j, cost);
//             pq.push(edge);
//         }
//         visited[0] = true;

//         while (!pq.empty() && count > 0) {
//             Edge edge = pq.top();
//             pq.pop();
//             int point1 = edge.point1;
//             int point2 = edge.point2;
//             int cost = edge.cost;
//             if (!visited[point2]) {
//                 result += cost;
//                 visited[point2] = true;
//                 for (int j = 0; j < sz; j++) {
//                     if (!visited[j]) {
//                         int distance = abs(points[point2][0] - points[j][0]) +
//                                        abs(points[point2][1] - points[j][1]);
//                         pq.push(Edge(point2, j, distance));
//                     }
//                 }
//                 count--;
//             }
//         }
//         return result;
//     }
// };

int main() {
    vector<vector<int>> points = {{0, 0}, {2, 2}, {3, 10}, {5, 2}, {7, 0}};
    Solution solution;
    cout << "Minimum Cost to Connect Points = " << solution.minCostConnectPoints(points) << endl;
    return 0;
}


#include <iostream>
using namespace std;
int main(){
    
    return 0;
}