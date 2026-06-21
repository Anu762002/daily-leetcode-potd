#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int maxIceCream(vector<int>& costs, int coins) {
        int cnt=0;
        sort(costs.begin(),costs.end());
        for(auto it : costs){
            if(it<=coins){
                cnt++;
                coins-=it;
            }
            else break;
        }
        return cnt;
    }
};