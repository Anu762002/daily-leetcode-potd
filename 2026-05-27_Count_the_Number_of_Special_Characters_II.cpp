#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int numberOfSpecialChars(string s) {
        int n=s.size();
        map<char,int>st,xt,curr;
        for(auto it: s){
            if(it<='z' && it>='a') st[it]++;
            else xt[it]++;
        }
        int cnt=0;
        for(auto it: s){
            if(it>='A' && it<='Z'){
                if(!curr.count(it)){
                    if(curr[tolower(it)]!=0 && curr[tolower(it)]==st[tolower(it)]) cnt++;
                }
            }
            curr[it]++;
        }
        return cnt;
    }
};