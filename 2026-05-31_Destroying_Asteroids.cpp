#include<bits/stdc++.h>
using namespace std;
#define ll long long
class Solution {
public:
    bool asteroidsDestroyed(int mass, vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int n=nums.size();
        vector<ll>v(n);
        v[0]=nums[0];
        for(int i=1;i<n;i++){
            v[i]=nums[i]+v[i-1];
        }
        if(mass<nums[0]) return 0;
        for(int i=1;i<n;i++){
            if(nums[i]>(v[i-1]+mass)) return 0;
        }
        return 1;
    }
};