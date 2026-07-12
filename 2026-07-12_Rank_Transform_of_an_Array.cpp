#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& nums) {
        int n=nums.size();
        vector<int>ans(n);
        set<int>st(nums.begin(),nums.end());
        int rank=1;
        map<int,int>mpp;
        for(auto it: st){
            mpp[it]=rank;
            rank++;
        }
        for(int i=0;i<n;i++){
            int no=nums[i];
            ans[i]=mpp[no];
        }
        return ans;
    }
};