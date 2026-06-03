#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int earliestFinishTime(vector<int>& landt ,vector<int>& landd, vector<int>& watert, vector<int>& waterd) {
        int ans=INT_MAX;
        int n=landd.size();
        int m=waterd.size();
        vector<pair<int,int>>land,water;
        for(int i=0;i<n;i++){
            land.push_back({landt[i],landd[i]});
        }
        for(int i=0;i<m;i++){
            water.push_back({watert[i],waterd[i]});
        }
        int land_earl=INT_MAX;
        int water_earl=INT_MAX;
        for(int i=0;i<n;i++){
            land_earl=min(land_earl,land[i].first+land[i].second);
        }
        for(int i=0;i<m;i++){
            water_earl=min(water_earl,water[i].first+water[i].second);
        }
        int t1=sol(land_earl,water);
        int t2=sol(water_earl,land);
        return min(t1,t2);
    }
    int sol(int st,vector<pair<int,int>>nums){
        int ans=INT_MAX;
        for(auto [s,d]: nums){
            int y=max(st,s)+d;
            ans=min(ans,y);
        }
        return ans;
    }
};