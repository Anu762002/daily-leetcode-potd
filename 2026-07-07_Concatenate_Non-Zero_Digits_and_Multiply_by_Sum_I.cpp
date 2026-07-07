#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        int n=nums.size();
        int odd=0;
        int l=0,r=0;
        int ans=0;
        while(r<n){
            if(nums[r]%2!=0) odd++;
            if(odd>k){
                while(odd!=k){
                    if(nums[l]%2!=0) odd--;
                    l++;
                }
            }
            if(odd==k) ans++;
            r++;
        }
        return ans;
    }
};