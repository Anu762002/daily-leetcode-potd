#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        int n=nums.size();
        map<int,int>mpp;
        int check=1;

        for(auto it: nums) {
            mpp[it]++;
            if(mpp[it]>k){
                check=0;
            }
        }
        if(check) return n;
        int ans=0;
        int l=0,r=0;
        map<int,int>mp;
        while(r<n){
            if(mp[nums[r]]==k){
                while(nums[l]!=nums[r]){
                    mp[nums[l]]--;
                    l++;
                }
                mp[nums[l]]--;
                l++;
            }
            
            ans=max(ans,r-l+1);
            mp[nums[r]]++;
            r++;
        }
        return ans;
    }
};