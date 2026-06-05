#include<bits/stdc++.h>
using namespace std;
#define ll long long
class Solution {
public:
ll dp[19][20][11][11][2][2];
    ll solve(int ind, int sum, int prev1, int prev2, bool started, bool tight, string s ) {
        if ( ind == s.size() ) return sum;
        if ( dp[ind][sum][prev1][prev2][started][tight] != -1 ) return dp[ind][sum][prev1][prev2][started][tight];
        ll cnt = 0;
        int dig = s[ind] - '0';
        int limit = tight ? dig : 9;
        for ( int i=0; i<=limit; i++ ) {
            if ( ! started )  cnt += solve(ind+1, sum, ((i != 0) ? i : prev1 ), prev2, i != 0, tight && (i == dig), s );
            else if ( prev1 == 10 ) {
                cnt += solve(ind+1, sum, i, prev2, started, tight && (i == dig), s);
            }
            else if ( prev2 == 10 ) {
                cnt += solve(ind+1, sum, prev1, i, started, tight && (i == dig), s );
            }
            else {
                ll newsum = sum ;
                if ( (prev1 < prev2 && prev2 > i) || (prev1 > prev2 && prev2 < i) ) newsum += 1;
                cnt += solve(ind+1, newsum, prev2, i, started, tight && (i == dig), s );
            } 
        }
        return dp[ind][sum][prev1][prev2][started][tight] = cnt;
    }

    ll calSolve(ll n) {
        string s = to_string(n);
        memset(dp, -1, sizeof(dp));
        return solve(0, 0, 10, 10, 0, 1, s);
    }

    long long totalWaviness(long long num1, long long num2) {
        return calSolve(num2) - calSolve(num1-1);
    }
};