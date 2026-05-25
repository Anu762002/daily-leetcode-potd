#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool canReach(string s, int l, int h) {
        int n = s.size();
        vector<int> dp(n,0);
        dp[0] = 1;
        int cnt = 0;
        for(int i=1;i<n;i++){
            // add entering index
            if(i-l >= 0)
                cnt += dp[i-l];
            // remove leaving index
            if(i-h-1 >= 0)
                cnt -= dp[i-h-1];
            if(cnt > 0 && s[i]=='0')
                dp[i]=1;
        }
        return dp[n-1];
    }
};