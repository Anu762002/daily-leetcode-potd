#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int largestInteger(vector<int>& nums, int k) {
        int n=nums.size();
        vector<int>v(51,0);
        for(int i=0;i<=n-k;i++){
            set<int>st;
            for(int j=i;j<i+k;j++){
                st.insert(nums[j]);
            }
            for(auto it: st) v[it]++;
        }
        int ans=-1;
        for(int i=50;i>=0;i--){
            if(v[i]==1){
                ans=max(ans,i);
                break;
            }
        }
        return ans;
    }
};