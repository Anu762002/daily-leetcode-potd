#include<bits/stdc++.h>
using namespace std;
#define mod 1000000007
#define ll long long
// ashu soln
class Solution {
public:
    vector<vector<ll>> dp;
    ll LOG, n;
    vector<ll> depth;
    vector<vector<ll>> adj;

    void calDepth(int node, int par) {
        for (auto &it : adj[node]) {
            if (it == par) continue;
            depth[it] = 1 + depth[node];
            dp[0][it] = node;
            calDepth(it, node);
        }
    }

    void binaryLifting() {
        for (int i = 1; i <= LOG; i++) {
            for (int j = 1; j <= n; j++) {
                if (dp[i - 1][j] == -1) continue;
                dp[i][j] = dp[i - 1][dp[i - 1][j]];
            }
        }
    }

    ll kthAncestor(int node, int k) {
        int par = node;
        while (k) {
            int ind = k & -k;
            int idx = log2(ind);
            par = dp[idx][par];
            if (par == -1) break;
            k -= ind;
        }
        return par;
    }

    ll findLCA(int u, int v) {
        if (depth[u] != depth[v]) {
            if (depth[u] < depth[v]) swap(u, v);
            int diff = depth[u] - depth[v];
            u = kthAncestor(u, diff);
        }

        for (int i = LOG; i >= 0; i--) {
            if (dp[i][u] != dp[i][v]) {
                u = dp[i][u];
                v = dp[i][v];
            }
        }

        if (u == v) return u;
        return dp[0][u];
    }

    ll expo(ll a, ll b) {
        if (b < 0) return 0;
        if (b == 0) return 1;

        ll half = expo(a, b / 2);

        if (b & 1)
            return (1LL * a % mod * half % mod * half % mod) % mod;

        return (1LL * half % mod * half % mod) % mod;
    }

    vector<int> assignEdgeWeights(vector<vector<int>>& edges, vector<vector<int>>& queries) {
        n = edges.size() + 1;

        adj.resize(n + 1);

        for (auto &it : edges) {
            ll u = it[0], v = it[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        LOG = ceil(log2(n));

        dp.resize(LOG + 1, vector<ll>(n + 1, -1));
        depth.resize(n + 1);

        calDepth(1, 0);
        binaryLifting();

        vector<int> ans;

        for (auto &it : queries) {
            int u = it[0], v = it[1];

            int lca = findLCA(u, v);

            ll tot = depth[v] + depth[u] - 2 * depth[lca];

            ans.push_back(expo(2, tot - 1) % mod);
        }

        return ans;
    }
};