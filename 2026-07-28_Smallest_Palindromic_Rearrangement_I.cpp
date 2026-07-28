#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    string smallestPalindrome(string s) {
        int n=s.length();
        string temp;
        string ans;
        if(n%2==0){
            for(int i=0;i<n/2;i++){
                temp+=s[i];
            }
            sort(temp.begin(),temp.end());
            ans+=temp;
            reverse(temp.begin(),temp.end());
            ans+=temp;
        }
        else{
            for(int i=0;i<n/2;i++){
                temp+=s[i];
            }
            sort(temp.begin(),temp.end());
            ans+=temp;
            ans+=s[n/2];
            reverse(temp.begin(),temp.end());
            ans+=temp;
        }
        return ans;
    }
};