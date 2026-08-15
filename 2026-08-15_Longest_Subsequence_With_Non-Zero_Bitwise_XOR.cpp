#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int longestSubsequence(vector<int>& nums) {
        int n=nums.size();
        int x=0;
        int maxi=0;
        for(auto it: nums){
            x=it^x;
            maxi=max(it,maxi);
        }
        if(maxi==0) return 0;
        if(x==0) return n-1;
        return n;
    }
};