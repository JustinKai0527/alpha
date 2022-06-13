#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <unordered_set>
#include <cmath>

using namespace std;

template <> struct hash<std::pair<int, int>> {
    inline size_t operator()(const std::pair<int, int> &v) const {
        std::hash<int> int_hasher;
        return int_hasher(v.first) ^ int_hasher(v.second);
    }
};

class Solution {
public:
    int countLatticePoints(vector<vector<int>>& circles) {
        unordered_set<pair<int,int>> hashmap;
        int num = 0;
        int size = circles.size();
        
        for(int i=0; i<size; i++){
            int y=circles[i][1]-circles[i][2];
            int temp = circles[i][1]+circles[i][2];
            // cout <<"???????"<<y<<temp<<endl;
            for(y; y<=temp; y++){
                int Xtemp = (int)sqrt(pow(circles[i][2],2)-pow(abs(circles[i][1]-y),2));
                // cout <<"_*()&*^&"<<Xtemp<<endl;
                int boundary = circles[i][0]+Xtemp;
                for(int x = circles[i][0]-Xtemp; x<=boundary; x++){
                    if(hashmap.count({y,x}) <= 0){
                        num++;
                        hashmap.insert({y,x});
                        // cout <<y<<x<<endl;
                    }
                    // cout <<x<<y<<endl;
                }
            }
        }

        return num;
    }
};