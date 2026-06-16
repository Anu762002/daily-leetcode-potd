#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    string processStr(string s) {
        int n=s.size();
        string curr="";
        for(int i=0;i<n;i++){
            if(s[i]=='*'){
                if(curr.size()>0)curr.pop_back();
                else continue;
            }
            else if(s[i]=='#'){
                curr=curr+curr;
            }
            else if(s[i]=='%'){
                reverse(curr.begin(),curr.end());
            }
            else curr+=s[i];
        }
        return curr;
    }
};