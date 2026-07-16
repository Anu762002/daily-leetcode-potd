#include<bits/stdc++.h>
using namespace std;
#define ll long long 
class Solution {
public:
    long long gcdSum(vector<int>& nums) {
        int n=nums.size();
        vector<ll>mx(n),g(n);
        mx[0]=nums[0];
        for(int i=1;i<n;i++){
            mx[i]=max(mx[i-1],(ll)nums[i]);
        }
        for(int i=0;i<n;i++){
            g[i]=gcd((ll)nums[i],mx[i]);
        }
        sort(g.begin(),g.end());
        ll ans=0;
        int l=0;
        int r=n-1;
        while(l<r){
            ans+=gcd(g[l],g[r]);
            l++;
            r--;
        }
        return ans;
    }
};