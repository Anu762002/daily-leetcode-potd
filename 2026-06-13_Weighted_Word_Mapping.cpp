#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    string mapWordWeights(vector<string>& nums, vector<int>& w) {
        
        string ans="";
        for(auto it: nums){
            int cnt=0;
            for(auto it2: it){
                cnt+=(w[it2-'a']);
            }
            cnt=cnt%26;
            int x=25-cnt;
            ans+=('a'+x);
        }
        return ans;
    }
};