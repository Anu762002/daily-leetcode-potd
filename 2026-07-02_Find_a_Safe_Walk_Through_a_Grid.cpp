#include<bits/stdc++.h>
using namespace std;
#define tp tuple<int,int,int>
class Solution {
public:
    
    bool findSafeWalk(vector<vector<int>>& nums, int k) {
        int n=nums.size();
        int m=nums[0].size();
        vector<vector<int>>dis(n,vector<int>(m,-1));
        priority_queue<tp,vector<tp>,greater<tp>>pq;
        pq.push({0+nums[0][0],0,0});

        vector<int>dx={-1,1,0,0};
        vector<int>dy={0,0,-1,1};
        while(pq.size()){
            auto [d,i,j]=pq.top();
            pq.pop();
            if(dis[i][j]>=0) continue;
            dis[i][j]=d;
            for(int x=0;x<4;x++){
                int ni=i+dx[x];
                int nj=j+dy[x];
                if(ni>=0 && nj>=0 && ni<n && nj<m ){
                    pq.push({d+nums[ni][nj],ni,nj});
                }
            }
        }
        return dis[n-1][m-1]<k;
    }
    
};