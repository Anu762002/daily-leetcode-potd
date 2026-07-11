#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int countCompleteComponents(int n, vector<vector<int>>& ed) {
        vector<vector<int>>adj(n);
        set<pair<int,int>>st;
        for(auto it: ed){
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
            st.insert({it[0],it[1]});
            st.insert({it[1],it[0]});
        }
        int ans=0;
        vector<int>vis(n,0);
        for(int i=0;i<n;i++){
            if(vis[i]==0){
                vis[i]=1;
                vector<int>x;
                x.push_back(i);
                dfs(i,vis,adj,x);
                bool f=1;
                for(int j=0;j<x.size();j++){
                    for(int k=j+1;k<x.size();k++){
                        if(!st.count({x[j],x[k]})){
                            f=0;
                            break;
                        }
                    }
                }
                if(f) ans++;
            }
        }
        return ans;
    }
    void dfs(int node,vector<int>&vis,vector<vector<int>>&adj,vector<int>&x){
        int n=vis.size();
        for(auto it: adj[node]){
            if(vis[it]==0){
                x.push_back(it);
                vis[it]=1;
                dfs(it,vis,adj,x);
            }
        }
    }
};