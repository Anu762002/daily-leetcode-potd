#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int minElement(vector<int>& nums) {
        int n=nums.size();
        int ans=1e9;
        for(auto it: nums){
            string s=to_string(it);
            int sum=0;
            for(auto bt: s) sum+=(bt-'0');
            ans=min(ans,sum);
        }
        return ans;
    }
};