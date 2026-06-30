#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int numberOfSubstrings(string s) {
        int n=s.size();
        int cnt=0;
        int i=0,j=0;
        vector<int>v(3,0);
        while(j<n){
            char curr=s[j];
            v[curr-'a']++;
            while(v[0]>0 && v[1]>0 && v[2]>0){
                cnt+=(n-j);
                char left=s[i];
                v[left-'a']--;
                i++;
            }
            j++;
        }
        return cnt;
    }
};