#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int maxProduct(int n) {
        vector<int>v;
        while(n>0){
            int x=n%10;
            v.push_back(x);
            n=n/10;
        }
        sort(v.begin(),v.end());
        int s=v.size();
        if(v[s-1]!=0 && v[s-2]!=0) return v[s-1]*v[s-2];
        else return 0;
    }
};