#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> leftRightDifference(vector<int>& nums) {
        int n=nums.size();
        vector<int>pre,suf(n,0);
        pre.push_back(nums[0]);
        for(int i=1;i<n;i++){
            pre.push_back(pre[i-1]+nums[i]);
        }
        suf[n-1]=nums[n-1];
        for(int j=n-2;j>=0;j--){
            suf[j]=suf[j+1]+nums[j];
        }
        vector<int>ans(n,0);
        for(int i=0;i<n;i++){
            ans[i]=abs(pre[i]-suf[i]);
        }
        return ans;
    }
};