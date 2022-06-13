#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Edge{
public:

    Edge(int _start, int _end, int dis): start(_start), end(_end), distance(dis){};
    int start;
    int end;
    int distance;

};

// bool operator<(const Edge& edge1, const Edge& edge2) {    //use for sort to class 
//     return edge1.distance < edge2.distance;
// }

bool compare(const Edge& edge1, const Edge& edge2){
    return edge1.distance < edge2.distance;
}

int main(){
    vector<Edge> edge;
    for(int i=0; i<10; i++){
        Edge e(i,i+1,10-i);
        edge.push_back(e);
    }
    // sort(edge.begin(),edge.end());
    sort(edge.begin(),edge.end(),compare);
    for(int i=0; i<10; i++){
        cout <<edge[i].distance<<" ";
    }
    return 0;
}