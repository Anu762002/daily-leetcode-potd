#include<bits/stdc++.h>
using namespace std;
#define ll long long
class Solution {
public:
vector<pair<ll,ll>> segTree; // min, max

    void buildSegTree(int i, int l, int r, vector<int> &arr ) {
        if ( l == r ) {segTree[i] = {arr[l], arr[l]}; return ;}
        int mid = ( l + r ) / 2;
        buildSegTree(2*i+1, l, mid, arr);
        buildSegTree(2*i+2, mid+1, r, arr);
        ll mini = min(segTree[2*i+1].first, segTree[2*i+2].first);
        ll maxi = max(segTree[2*i+1].second, segTree[2*i+2].second);
        segTree[i] = { mini, maxi };
    }

    pair<ll,ll> query(int i, int l, int r, int left, int right ) {
        if ( l > right || r < left ) { 
            return { INT_MAX, INT_MIN } ;
        }
        if ( l >= left && r <= right ) return segTree[i];
        int mid = ( l + r ) / 2;
        pair<ll,ll> leftChild = query(2*i+1, l, mid, left, right);
        pair<ll,ll> rightChild = query(2*i+2, mid+1, r, left, right);
        ll mini = min(segTree[2*i+1].first, segTree[2*i+2].first);
        ll maxi = max(segTree[2*i+1].second, segTree[2*i+2].second);
        return { min(leftChild.first, rightChild.first), max(leftChild.second, rightChild.second)};
    }

    long long maxTotalValue(vector<int>& nums, int k) {
        int n = nums.size();
        segTree.resize(4*n);
        buildSegTree(0, 0, n-1, nums);
        ll ans = 0;

        priority_queue<tuple<ll,ll,ll>> pq; // val, i, j
        ll cnt = 0;

        for ( int i=0; i<n; i++ ) {
            pair<ll,ll> res = query(0, 0, n-1, i, n-1);
            pq.push({ res.second - res.first, i, n-1});
            auto [val, ii, jj] = pq.top();
            }
        
        while (cnt < k) {
            auto [val, i, j] = pq.top(); pq.pop();
            ans = 0LL + ans + val;
            cnt ++;
            if ( j-1 >= i) {
                pair<ll,ll> newres = query(0, 0, n-1, i, j-1);
                pq.push({newres.second - newres.first, i, j-1});
            }
        }
        return ans;
    }
};