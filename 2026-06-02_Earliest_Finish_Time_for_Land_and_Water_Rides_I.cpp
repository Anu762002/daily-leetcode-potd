#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int earliestFinishTime(vector<int>& landStartTime, vector<int>& landDuration, vector<int>& waterStartTime, vector<int>& waterDuration) {
        int n=landStartTime.size();
        int m=waterStartTime.size();
        int ans=INT_MAX;
        for(int i=0;i<n;i++){
            
            for(int j=0;j<m;j++){
                
                int landstart=landStartTime[i];
                int landend=landstart+landDuration[i];
                int waterstart0=max(landend,waterStartTime[j]);
                int time1=waterstart0+waterDuration[j];

                int waterstart=waterStartTime[j];
                int waterend=waterstart+waterDuration[j];
                int landstart0=max(waterend,landStartTime[i]);
                int time2=landstart0+landDuration[i];

                ans=min(ans,min(time1,time2));
                
            }
        }
        return ans;
    }
};