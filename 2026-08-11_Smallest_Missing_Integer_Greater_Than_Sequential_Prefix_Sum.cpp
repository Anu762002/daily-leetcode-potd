#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int missingInteger(vector<int>& nums) {
        int n=nums.size();
        if(n==1) return nums[0]+1;
        set<int>st;
        
        for(auto it: nums) st.insert(it);
        int i;
        for(i=1;i<n;i++){
            if(nums[i]!=nums[i-1]+1) break;
            
        }
        if(i>=n){
            return accumulate(nums.begin(),nums.end(),0);
        }
        cout<<i;
        int sum=(nums[0]-1)*(i)+((i)*(i+1))/2;
        while(st.count(sum)) sum++;
        return sum;
    }
};