#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int minimumLines(vector<vector<int>>& stockPrices) {
        int size = stockPrices.size();
        int min = 1;
        long long int delta_x1,delta_y1;
        long long int delta_x2,delta_y2;
        if(size == 1)  return 0;
        if(size == 2)  return 1;
        // cout <<size<<endl;
        sort(stockPrices.begin(),stockPrices.end());
         
        for(int i=1; i<size-1; i++){
            // cout <<stockPrices[i-1][0]<<endl;
            delta_x1 = stockPrices[i][0]-stockPrices[i-1][0];
            delta_y1 = stockPrices[i][1]-stockPrices[i-1][1];
            delta_x2 = stockPrices[i+1][0]-stockPrices[i][0];
            delta_y2 = stockPrices[i+1][1]-stockPrices[i][1];
            // cout <<i<<" "<<delta_x1<<" "<<delta_y1<<endl<<" "<<delta_x2<<" "<<delta_y2<<endl;
            if(delta_x1*delta_y2 == delta_x2*delta_y1)  continue;
            else{  
                min++;
                cout <<min<<endl;
            }  
        }

        return min;
    }
};

//complete