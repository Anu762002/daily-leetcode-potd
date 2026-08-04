#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
        int n=nums.size();
        int maxi=INT_MIN;
        int mini=INT_MAX;
        set<int>st;
        for(int i=0;i<n;i++){
            maxi=max(nums[i],maxi);
            mini=min(nums[i],mini);
            st.insert(nums[i]);
        }
        cout<<maxi<<endl;
        cout<<mini<<endl;
        vector<int>v;
        for(int i=mini+1;i<maxi;i++){
            if(!st.count(i)) {
                v.push_back(i);
            }
        }
        return v;
    }
};