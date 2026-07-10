#include<bits/stdc++.h>
using namespace std;

constexpr int L = 18, N = 100001;
using int2 = pair<int, int>;

int up[L][N], pos[N];
int2 xId[N];

class Solution {
public:
    static int cnt(int u, int v, int maxL) {
        if (u == v) return 0;
        if (up[0][u] >= v) return 1;
        if (up[maxL - 1][u] < v) return -1;

        int step = 0;
        for (int j = maxL - 1; j >= 0; j--) {
            if (up[j][u] < v) {
                step += (1 << j);
                u = up[j][u];
            }
        }
        return step + 1;
    }

    vector<int> pathExistenceQueries(int n, vector<int>& nums, int maxDiff, vector<vector<int>>& queries) {

        int maxL = 32 - __builtin_clz(n);

        for (int i = 0; i < n; i++)
            xId[i] = {nums[i], i};

        sort(xId, xId + n);

        for (int i = 0; i < n; i++)
            pos[xId[i].second] = i;

        for (int l = 0, r = 0; l < n; l++) {
            while (r + 1 < n && xId[r + 1].first - xId[l].first <= maxDiff)
                r++;
            up[0][l] = r;
        }

        for (int j = 1; j < maxL; j++) {
            for (int i = 0; i < n; i++) {
                up[j][i] = up[j - 1][up[j - 1][i]];
            }
        }

        vector<int> ans;
        ans.reserve(queries.size());

        for (auto &q : queries) {
            pair<int, int> p = minmax(pos[q[0]], pos[q[1]]);
            int u = p.first;
            int v = p.second;
            ans.push_back(cnt(u, v, maxL));
        }

        return ans;
    }
};