#include<bits/stdc++.h>
using namespace std;
constexpr int MOD = 1'000'000'007;

class Solution {
public:
    int zigZagArrays(int n, int l, int r) {
        int m = r - l + 1;
        vector<int> dp0(m, 0);
        vector<int> dp1(m, 0);
        vector<int> sum0(m + 1, 0);
        vector<int> sum1(m + 1, 0);

        for (int i = 0; i < m; i++) {
            dp0[i] = dp1[i] = 1;
        }

        for (int i = 1; i < n; i++) {
            for (int j = 0; j < m; j++) {
                sum0[j + 1] = (sum0[j] + dp0[j]) % MOD;
                sum1[j + 1] = (sum1[j] + dp1[j]) % MOD;
            }

            for (int j = 0; j < m; j++) {
                dp0[j] = (sum1[m] - sum1[j + 1] + MOD) % MOD;
                dp1[j] = sum0[j];
            }
        }

        auto op = [](int acc, int x) { return (acc + x) % MOD; };
        long long ans0 = 0, ans1 = 0;

        for(auto x : dp0) ans0 = (ans0 + x) % MOD;
        for(auto x : dp1) ans1 = (ans1 + x) % MOD;

        return (ans0 + ans1) % MOD;
    }
};