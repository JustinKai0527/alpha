#include <iostream>
#include <vector>
#include <stack>
#include <queue>

using namespace std;

class Solution {
public:
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        vector<vector<int>> paths;
        if(graph.size() == 0)    return paths;

        vector<int> path;
        queue<vector<int>> q;
        path.push_back(0);                              //no need check because it's a directed Graph
        q.push(path);
        while(!q.empty()){
            vector<int> v;
            v = q.front();
            for(int i=0; i<graph[v.back()].size(); i++){
                v.push_back(graph[v.back()][i]);
                q.push(v);
                v.pop_back();
                if(graph[v.back()][i] == graph.size()-1){
                    paths.push_back(q.back());
                }
            }
            q.pop();
        }
        return paths;
    }
};

class Solution {                        // leetcode example queue version
public:
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        vector<vector<int>> paths;
        if (graph.size() == 0) {
            return paths;
        }

        vector<int> path;
        queue<vector<int>> q;
        path.push_back(0);
        q.push(path);

        while (!q.empty()) {
            vector<int> currentPath = q.front();
            q.pop();
            int node = currentPath.back();
            for (int nextNode : graph[node]) {
                vector<int> tmpPath(currentPath.begin(), currentPath.end());
                tmpPath.push_back(nextNode);
                if (nextNode == graph.size() - 1) {
                    paths.push_back(tmpPath);
                } else {
                    q.push(tmpPath);
                }
            }
        }
        return paths;
    }
};


class Solution {                        //這題為何不用stack 是因為他是一直走下去的，並沒有返回的路線
public:
    void dfs(vector<vector<int>>& graph, vector<int>& path, vector<vector<int>>& paths, int node){
        path.push_back(node);
        if(node == graph.size()-1){
            paths.push_back(path);
            return;
        }
        else{
            for(int i=0; i<graph[node].size(); i++){
                dfs(graph,path,paths,graph[node][i]);
                path.pop_back();                            //為何要加pop_back();   因為path進入dfs，然後看他是否進行，若再進入for，則看他進入幾次
            }                                               //就pop幾次，要刪掉
        }
    }
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        vector<vector<int>> paths;
        if(graph.size() == 0)    return paths;
        vector<int> path;
        dfs(graph,path,paths,0);
        return paths;
    }
};


class Solution {
public:
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        vector<vector<int>> paths;
        vector<int> path;
        stack<vector<int>> s;
        if(graph.size() == 0)    return paths;
        path.push_back(0);
        s.push(path);
        while(!s.empty()){
            
        }
    }
};






class Solution {                            //leetcode example dfs
public:
    // DFS
    void dfs(vector<vector<int>>& graph, int node, vector<int>& path,vector<vector<int>>& paths) {
        path.push_back(node);
        if (node == graph.size() - 1) {
            paths.emplace_back(path);
            return;
        }
        vector<int> nextNodes = graph[node];
        for (int nextNode : nextNodes) {
            dfs(graph, nextNode, path, paths);
            path.pop_back();
        }
    }

    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        vector<vector<int>> paths;
        if (graph.size() == 0) {
            return paths;
        }
        vector<int> path;
        dfs(graph, 0, path, paths);
        return paths;
    }
};