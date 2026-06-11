#include<bits/stdc++.h>
using namespace std;
#define mod 1000000007
#define ll long long
class Solution {
public:
    // ashu soln
    vector<ll> depth;
    vector<ll> facto;
    int maxD;
    void dfs(int node, int par, vector<vector<int>> &adj ) {
        for ( auto it : adj[node] ) {
            if ( it == par ) continue;
            depth[it] = 1 + depth[node];
            dfs(it, node, adj);
        }
    }

    void factorial() {
        for ( int i=1; i<=maxD; i++ ) {
            facto[i] = (1LL * facto[i-1] % mod * i % mod) % mod ;
        }
    }

    ll expo(ll a, ll b){
        if ( b == 0 )  return 1;
        ll half = expo(a, b/2) ;
        if ( b & 1 ) return (a % mod * half % mod * half % mod) % mod;
        else return (half % mod * half % mod) % mod; 
    }

    int assignEdgeWeights(vector<vector<int>>& edges) {
        ll n = edges.size() + 1;
        vector<vector<int>> adj(n+1);
        depth.resize(n+1, 0);
        for ( auto it : edges ) {
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }

        dfs(1, 0, adj);

        facto.resize(n+1, 1);
        maxD = *max_element(depth.begin(), depth.end());
        factorial();

        ll cnt = 0;

        return expo(2, maxD-1) % mod;

    }
};