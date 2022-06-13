#include <iostream> 
#include <unordered_set>

using namespace std;

class Solution {
public:
    int numJewelsInStones(string jewels, string stones) {
        unordered_set<char> hashmap;
        
        for(int i=0; i<jewels.size(); i++){
            hashmap.insert(jewels[i]);
        }

        int count = 0;

        for(int j=0; j<stones.size(); j++){
            if(hashmap.count(stones[j]) > 0)  count++;
        }

        return count;
    }
};