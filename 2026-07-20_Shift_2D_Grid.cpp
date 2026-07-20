#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<vector<int>> shiftGrid(vector<vector<int>>& g, int k) {
        int n=g.size();
        int m=g[0].size();
        k %= (m*n);
        vector<int>nums;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                nums.push_back(g[i][j]);
            }
        }
        vector<vector<int>>ans(n,vector<int>(m));
        int ind=(m*n-k);
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                ind=ind%(m*n);
                ans[i][j]=nums[ind];
                ind++;
                
            }
        }
        return ans;
    }
};