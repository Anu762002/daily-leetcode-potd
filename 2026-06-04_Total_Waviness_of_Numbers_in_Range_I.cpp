#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int totalWaviness(int num1, int num2) {
        int ans=0;
        for(int i=num1;i<=num2;i++){
            string s=to_string(i);
            ans+=peak(s);
            ans+=vally(s);
        }
        return ans;
    }
    int peak(string s){
        int n=s.size();
        int ans=0;
        for(int i=1;i<n-1;i++){
            if(s[i]>s[i-1] && s[i]>s[i+1]) ans++;
        }
        return ans;
    }
    int vally(string s){
        int n=s.size();
        int ans=0;
        for(int i=1;i<n-1;i++){
            if(s[i]<s[i-1] && s[i]<s[i+1]) ans++;
        }
        return ans;
    }
};