#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {
        int n=nums.size();
        int cnt=0;
        vector<int>ans;
        for(auto it: nums){
            if(it<pivot){
                ans.push_back(it);
            }
            if(it==pivot) cnt++;
        }
        for(int i=0;i<cnt;i++){
            ans.push_back(pivot);
        }
        for(auto it: nums){
            if(it>pivot){
                ans.push_back(it);
            }
        }
        return ans;
    }
};