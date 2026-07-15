#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int gcdOfOddEvenSums(int n) {
        int oddsum=0;
        int evensum=0;
        for(int i=1;i<=2*n;i++){
            if(i%2==0) evensum+=i;
            else oddsum+=i;
        }
        return gcd(oddsum,evensum);
    }
};