// #include <iostream>
// #include <vector>
// using namespace std;

// int main(){
//     vector<vector<int>> a(10);
    
//     for(int i=0; i<a.size(); i++){
//         cout <<i<<endl;
//     }
//     return 0;
// }

#include <iostream>
#include <vector>
#include <stack>
using namespace std;

class Solution {
public:
    void DFS(int source, int destination, vector<vector<int>>& edges) {
        cout << "source = " << source << endl;
        if (stk.empty() == 1) return;
        stk.pop();
        if (source == destination) {
            ret = 1;
        }
        if (visited[source] == 0) { // unvisited
            visited[source] = 1;
            for (int i = 0; i < edges[source].size(); i++) {
                stk.push(edges[source][i]);
            }
        }
        if (stk.empty() == 1) return;
        DFS(stk.top(), destination, edges);
    }
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        visited.resize(n);
        vec.resize(n);
        for (int i = 0; i < edges.size(); i++) {
            vec[edges[i][0]].push_back(edges[i][1]);
            vec[edges[i][1]].push_back(edges[i][0]);
        }
        


        stk.push(source);

        for (int i = 0; i < vec.size(); i++) {
            cout << "head = " << i << " : ";
            for (int j = 0; j < vec[i].size(); j++) {
                cout << vec[i][j] << " ";
            }
            cout << endl;
        }
        DFS(source, destination, vec);
        return ret;
    }

private:
    stack<int> stk;
    vector<int> visited;
    vector<vector<int>> vec;
    int ret = 0;
};

int main() {
    Solution sol;
    vector<vector<int>> edges;
    int n;
    cin >> n;
    edges.resize(10);
    for (int i = 0; i < 10; i++) {
        int x, y;
        cin >> x >> y;
        edges[i].push_back(x);
        edges[i].push_back(y);
    }
    cout << sol.validPath(n, edges, 7, 5) << endl;
}