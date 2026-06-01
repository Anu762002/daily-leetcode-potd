#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int minimumCost(vector<int>& v) {
        sort(v.rbegin(),v.rend());
        int n=v.size();
        int ans=0;
        for(int i=0;i<n;i++){
            if((i+1)%3==0) continue;
            ans+=v[i];
        }
        return ans;
    }
};