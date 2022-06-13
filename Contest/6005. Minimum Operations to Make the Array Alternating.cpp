#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        vector<int> odd;
        vector<int> even;
        if(nums.size() == 1)  return 0;
        for(int i=0; i<nums.size(); i++){
            if(i%2 == 1){
                odd.push_back(nums[i]);
            }
            else{
                even.push_back(nums[i]);
            }
        }
        sort(odd.begin(),odd.end());
        sort(even.begin(),even.end());
        vector<int> odd_total;
        odd_total.push_back(1);
        vector<int> even_total;
        even_total.push_back(1);
        vector<int> odd_record;
        odd_record.push_back(odd[0]);
        vector<int> even_record;
        even_record.push_back(even[0]);

        int odd_max = odd[0];
        int odd_sum = 1;
        int even_max = even[0];
        int even_sum = 1;
        int odd_max_candidate;
        int odd_max_candidate_sum;
        int even_max_candidate;
        int even_max_candidate_sum;
        for(int i=0; i<odd.size(); i++){
            if(odd[i] == odd[i+1]){
                odd_total.back()++;
                if(odd_sum < odd_total.back()){
                    odd_max_candidate = odd_max;
                    odd_max_candidate_sum = odd_sum;
                    odd_max = odd_record.back();
                    odd_sum = odd_total.back();
                }
            }
            else{
                odd_total.push_back(1);
                odd_record.push_back(odd[i]);
            }
        }

        for(int i=0; i<even.size(); i++){
            if(even[i] == even[i+1]){
                even_total.back()++;
                if(even_sum < even_total.back()){
                    even_max_candidate = even_max;
                    even_max_candidate_sum = even_sum;
                    even_max = even_record.back();
                    even_sum = even_total.back();
                }
            }
            else{
                even_total.push_back(1);
                even_record.push_back(even[i]);
            }
        }
        if(even_max != odd_max)  return nums.size()-(even_sum+odd_sum);
        else{
            if(odd_max_candidate_sum+even_sum > odd_sum+even_max_candidate_sum){
                return nums.size()-(odd_max_candidate_sum+even_sum);
            }
        }
        return nums.size()-(odd_sum+even_max_candidate_sum);
    }
};