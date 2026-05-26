#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int numberOfSpecialChars(string s) {
        int n=s.size();
        set<char>st,xt;
        for(auto it: s){
            if(it<='z' && it>='a') st.insert(it);
            else xt.insert(it);
        }
        int cnt=0;
        for(auto it: st){
            
            if(xt.count(toupper(it))) cnt++;
        }
        return cnt;
    }
};