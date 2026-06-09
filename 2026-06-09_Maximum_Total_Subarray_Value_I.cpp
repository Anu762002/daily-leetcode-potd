#include<bits/stdc++.h>
using namespace std;
#define ll long long
class Solution {
public:
    long long maxTotalValue(vector<int>& nums, int k) {
        ll mini=1e10;
        ll maxi=0;
        for(auto it: nums){
            maxi=max(maxi,(ll)it);
            mini=min(mini,(ll)it);
        }
        return (maxi-mini)*k;
    }
};