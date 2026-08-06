#include<bits/stdc++.h>
using namespace std;
#define ll long long
class Solution {
public:
    int smallestNumber(int n, int t) {
        ll x=n*t;
        for(int i=n;i<=x;i++){
            string y=to_string(i);
            ll z=1;
            for(int j=0;j<y.size();j++){
                z=z*((y[j]-'0'));
            }
            if(z%t==0) return i;
        }
        return n*t;
    }
};