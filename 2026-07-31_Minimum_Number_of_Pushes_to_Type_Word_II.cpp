#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int minimumPushes(string word) {
        map<char,int>mpp;
        for(auto it: word){
            mpp[it]++;
        }
        priority_queue<int>pq;
        for(auto [a,b]:mpp){
            pq.push(b);
        }
        double i=1;
        long long ans=0;
        while(pq.size()){
            ans=ans+pq.top()*ceil(i/8);
            pq.pop();
            i++;
        }
        return ans;
    }
};