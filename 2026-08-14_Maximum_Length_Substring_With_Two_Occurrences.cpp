#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int maximumLengthSubstring(string s) {
        int n=s.size();
        int ans=0;
        for(int i=0;i<n;i++){
            map<int,int>mpp;
            for(int j=i;j<n;j++){
                mpp[s[j]]++;
                int f=1;
                for(auto [a,b]: mpp){
                    if(b>2){
                        f=0;
                        break;
                    }
                }
                if(f){
                    ans=max(ans,j-i+1);
                }
            }
        }
        return ans;
    }
};