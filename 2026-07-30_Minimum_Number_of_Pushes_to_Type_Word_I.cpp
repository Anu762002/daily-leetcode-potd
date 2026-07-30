#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int minimumPushes(string s) {
        int n=s.size();
        int x=n/8;
        int ans=8*x*(x+1)/2;
        ans+=(n-8*x)*(x+1);
        return ans;
    }
};