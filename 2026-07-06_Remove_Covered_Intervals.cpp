#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int removeCoveredIntervals(vector<vector<int>>& nums) {
        int n=nums.size();
        sort(nums.begin(),nums.end(),comp);
        int cnt=0;
        for(int i=0;i<n;i++){
            if(nums[i][0]==-1 ) continue;
            int x=nums[i][0];
            int y=nums[i][1];
            for(int j=i+1;j<n;j++){
                if(nums[j][0]==-1 ) continue;
                int a=nums[j][0];
                int b=nums[j][1];
                if(x<=a && y>=b){
                    nums[j][0]=-1;
                    cnt++;
                }
            }
        }
        return n-cnt;
    }
    static bool comp(vector<int>&a,vector<int>&b){
        if(a[0]==b[0]){
            return a[1]>b[1];
        }
        return a[0]<b[0];
    }
};