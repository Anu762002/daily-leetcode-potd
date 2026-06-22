#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int maxNumberOfBalloons(string s) {
        vector<int>v(26,0);
        for(auto it: s){
            v[it-'a']++;
        }
        int ans=INT_MAX;
        ans=min({ans,v[0],v[1],v[11]/2,v[14]/2,v[13]});
        return ans;
    }
};